#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>

#include <thread>
#include <atomic>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <grpc/grpc.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <google/protobuf/empty.pb.h>
#include "test.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;
using mosaic::ImageAndTextChunk;
using mosaic::TextResponse;
using mosaic::YourService;
using mosaic::ModelChunk;
using mosaic::IntValue;
using google::protobuf::Empty;

using std::thread;
using std::atomic_bool;
using std::chrono::milliseconds;

atomic_bool stop_thread(false);

int update_count = 1;


void ListenOnPort1337() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int port = 1337;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    std::cout << "Listening on port " << port << std::endl;

    while (!stop_thread) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Handle incoming connections on port 1337
        // You can add your logic here to handle the connections
        // For example:
        // std::cout << "Received connection on port 1337" << std::endl;

        close(new_socket);
    }

    close(server_fd);
}

class YourServiceImpl final : public YourService::Service {
    public:
        Status ProcessImageAndText(ServerContext* context, ServerReader<ImageAndTextChunk>* reader, TextResponse* response) override {
            ImageAndTextChunk chunk;
            std::vector<uint8_t> image_data;
            std::string text;

            while (reader->Read(&chunk)) {
                if (!chunk.text().empty()) {
                    text = chunk.text(); // Capture the text from the first chunk
                }
                image_data.insert(image_data.end(), chunk.chunk_data().begin(), chunk.chunk_data().end());
            }

            // Save image data to "image.jpg"
            std::ofstream output_file("image.jpg", std::ios::out | std::ios::binary);
            output_file.write(reinterpret_cast<const char*>(image_data.data()), image_data.size());
            output_file.close();

            // Process the image_data and generate the output_text
            std::string output_text = "Image received and saved as image.jpg with text: " + text; // Replace with actual processing logic
            std::cout << output_text << std::endl;
            std::string command = "python3 generate_caption.py image.jpg";
            FILE* pipe = popen(command.c_str(), "r");
            if (!pipe) {
                response->set_output_text("Error running Python script.");
                return Status(grpc::StatusCode::INTERNAL, "Failed to run Python script.");
            }

            // Wait for the Python script to finish working
            pclose(pipe);

            // Read the first line from the generated text file
            std::ifstream text_file("image_output.txt");
            if (!text_file) {
                response->set_output_text("Error opening output file.");
                return Status(grpc::StatusCode::INTERNAL, "Failed to open output file.");
            }

            std::getline(text_file, output_text);
            text_file.close();
            response->set_output_text(output_text);

            return Status::OK;
        }

        Status TrainModel(ServerContext* context, ServerReader<ImageAndTextChunk>* reader, TextResponse* response) override {
            ImageAndTextChunk chunk;
            std::vector<uint8_t> image_data;
            std::string text;

            while (reader->Read(&chunk)) {
                if (!chunk.text().empty()) {
                    text = chunk.text(); // Capture the text from the first chunk
                }
                image_data.insert(image_data.end(), chunk.chunk_data().begin(), chunk.chunk_data().end());
            }

            // Save image data to "image.jpg"
            std::ofstream output_file("image.jpg", std::ios::out | std::ios::binary);
            output_file.write(reinterpret_cast<const char*>(image_data.data()), image_data.size());
            output_file.close();

            // Process the image_data and generate the output_text
            std::string output_text = "Image received and saved as image.jpg with text: " + text; // Replace with actual processing logic
            std::cout << output_text << std::endl;
            std::string command = "python3 train_model.py image.jpg";
            command += " '<start> " + text + " <end>'";
            FILE* pipe = popen(command.c_str(), "r");
            if (!pipe) {
                response->set_output_text("Error running Python script.");
                return Status(grpc::StatusCode::INTERNAL, "Failed to run Python script.");
            }

            // Wait for the Python script to finish working
            pclose(pipe);
            response->set_output_text(output_text);

	    std::cout << " trainin the model is done succesfully" << std::endl;
            ++update_count;
            return Status::OK;
        }

        Status SendModelStream(ServerContext* context, const Empty* request, ServerWriter<ModelChunk>* writer) override {
            std::string model_filename = "model_scripted.pt"; // Specify the model file name
            std::ifstream model_file(model_filename, std::ios::binary);
            if (!model_file) {
                return Status(grpc::StatusCode::NOT_FOUND, "Model file not found.");
            }
            const int kChunkSize = 1024 * 1024;
            ModelChunk model_chunk;
            while (true) {
                // Read a chunk of data from the model file
                model_chunk.clear_chunk_data();
                model_chunk.mutable_chunk_data()->resize(kChunkSize);
                model_file.read(model_chunk.mutable_chunk_data()->data(), kChunkSize);
                const std::streamsize bytes_read = model_file.gcount();
                if (bytes_read == 0) {
                    break; // End of file
                }
                model_chunk.mutable_chunk_data()->resize(bytes_read);

                // Write the chunk to the server
                if (!writer->Write(model_chunk)) {
                    std::cout << "Error writing model chunk to server\n";
                }
            }

            return Status::OK;
        }

        Status ReceiveModelStream(ServerContext* context, ServerReader<ModelChunk>* reader, Empty* response) override {
            std::ofstream output_file("model_scripted.pt", std::ios::binary);
            ModelChunk model_chunk;
            while (reader->Read(&model_chunk)) {
                output_file.write(model_chunk.chunk_data().data(), model_chunk.chunk_data().size());
            }
            output_file.close();
            return Status::OK;
        }

        Status SendIntValue(ServerContext* context, const Empty* request, IntValue* response) override {
            int value = update_count; // You can set any integer value here
            response->set_value(value);
            update_count = 1;
            return Status::OK;
        }
};

void RunServer() {
    /*
    std::string server_address("192.168.137.29:8080"); // Specify the IP address and port
    */
    std::string server_address("192.168.1.107:8080"); // Specify the IP address and port
    YourServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main() {
    thread listen1337(ListenOnPort1337);

    RunServer();

    stop_thread = true;
    listen1337.join();

    return 0;
}

