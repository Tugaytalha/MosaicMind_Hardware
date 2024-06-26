// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: test.proto

#include "test.pb.h"
#include "test.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace mosaic {

static const char* Mosaic_method_names[] = {
  "/mosaic.Mosaic/ProcessImageAndText",
  "/mosaic.Mosaic/TrainModel",
  "/mosaic.Mosaic/SendModelStream",
  "/mosaic.Mosaic/SendIntValue",
  "/mosaic.Mosaic/ReceiveModelStream",
};

std::unique_ptr< Mosaic::Stub> Mosaic::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Mosaic::Stub> stub(new Mosaic::Stub(channel, options));
  return stub;
}

Mosaic::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_ProcessImageAndText_(Mosaic_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_TrainModel_(Mosaic_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_SendModelStream_(Mosaic_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_SendIntValue_(Mosaic_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ReceiveModelStream_(Mosaic_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  {}

::grpc::ClientWriter< ::mosaic::ImageAndTextChunk>* Mosaic::Stub::ProcessImageAndTextRaw(::grpc::ClientContext* context, ::mosaic::TextResponse* response) {
  return ::grpc::internal::ClientWriterFactory< ::mosaic::ImageAndTextChunk>::Create(channel_.get(), rpcmethod_ProcessImageAndText_, context, response);
}

void Mosaic::Stub::async::ProcessImageAndText(::grpc::ClientContext* context, ::mosaic::TextResponse* response, ::grpc::ClientWriteReactor< ::mosaic::ImageAndTextChunk>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::mosaic::ImageAndTextChunk>::Create(stub_->channel_.get(), stub_->rpcmethod_ProcessImageAndText_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::mosaic::ImageAndTextChunk>* Mosaic::Stub::AsyncProcessImageAndTextRaw(::grpc::ClientContext* context, ::mosaic::TextResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::mosaic::ImageAndTextChunk>::Create(channel_.get(), cq, rpcmethod_ProcessImageAndText_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::mosaic::ImageAndTextChunk>* Mosaic::Stub::PrepareAsyncProcessImageAndTextRaw(::grpc::ClientContext* context, ::mosaic::TextResponse* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::mosaic::ImageAndTextChunk>::Create(channel_.get(), cq, rpcmethod_ProcessImageAndText_, context, response, false, nullptr);
}

::grpc::ClientWriter< ::mosaic::ImageAndTextChunk>* Mosaic::Stub::TrainModelRaw(::grpc::ClientContext* context, ::mosaic::TextResponse* response) {
  return ::grpc::internal::ClientWriterFactory< ::mosaic::ImageAndTextChunk>::Create(channel_.get(), rpcmethod_TrainModel_, context, response);
}

void Mosaic::Stub::async::TrainModel(::grpc::ClientContext* context, ::mosaic::TextResponse* response, ::grpc::ClientWriteReactor< ::mosaic::ImageAndTextChunk>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::mosaic::ImageAndTextChunk>::Create(stub_->channel_.get(), stub_->rpcmethod_TrainModel_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::mosaic::ImageAndTextChunk>* Mosaic::Stub::AsyncTrainModelRaw(::grpc::ClientContext* context, ::mosaic::TextResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::mosaic::ImageAndTextChunk>::Create(channel_.get(), cq, rpcmethod_TrainModel_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::mosaic::ImageAndTextChunk>* Mosaic::Stub::PrepareAsyncTrainModelRaw(::grpc::ClientContext* context, ::mosaic::TextResponse* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::mosaic::ImageAndTextChunk>::Create(channel_.get(), cq, rpcmethod_TrainModel_, context, response, false, nullptr);
}

::grpc::ClientReader< ::mosaic::ModelChunk>* Mosaic::Stub::SendModelStreamRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request) {
  return ::grpc::internal::ClientReaderFactory< ::mosaic::ModelChunk>::Create(channel_.get(), rpcmethod_SendModelStream_, context, request);
}

void Mosaic::Stub::async::SendModelStream(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::grpc::ClientReadReactor< ::mosaic::ModelChunk>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::mosaic::ModelChunk>::Create(stub_->channel_.get(), stub_->rpcmethod_SendModelStream_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::mosaic::ModelChunk>* Mosaic::Stub::AsyncSendModelStreamRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::mosaic::ModelChunk>::Create(channel_.get(), cq, rpcmethod_SendModelStream_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::mosaic::ModelChunk>* Mosaic::Stub::PrepareAsyncSendModelStreamRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::mosaic::ModelChunk>::Create(channel_.get(), cq, rpcmethod_SendModelStream_, context, request, false, nullptr);
}

::grpc::Status Mosaic::Stub::SendIntValue(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::mosaic::IntValue* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::Empty, ::mosaic::IntValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendIntValue_, context, request, response);
}

void Mosaic::Stub::async::SendIntValue(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::mosaic::IntValue* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::Empty, ::mosaic::IntValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendIntValue_, context, request, response, std::move(f));
}

void Mosaic::Stub::async::SendIntValue(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::mosaic::IntValue* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendIntValue_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::mosaic::IntValue>* Mosaic::Stub::PrepareAsyncSendIntValueRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::mosaic::IntValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendIntValue_, context, request);
}

::grpc::ClientAsyncResponseReader< ::mosaic::IntValue>* Mosaic::Stub::AsyncSendIntValueRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendIntValueRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientWriter< ::mosaic::ModelChunk>* Mosaic::Stub::ReceiveModelStreamRaw(::grpc::ClientContext* context, ::google::protobuf::Empty* response) {
  return ::grpc::internal::ClientWriterFactory< ::mosaic::ModelChunk>::Create(channel_.get(), rpcmethod_ReceiveModelStream_, context, response);
}

void Mosaic::Stub::async::ReceiveModelStream(::grpc::ClientContext* context, ::google::protobuf::Empty* response, ::grpc::ClientWriteReactor< ::mosaic::ModelChunk>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::mosaic::ModelChunk>::Create(stub_->channel_.get(), stub_->rpcmethod_ReceiveModelStream_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::mosaic::ModelChunk>* Mosaic::Stub::AsyncReceiveModelStreamRaw(::grpc::ClientContext* context, ::google::protobuf::Empty* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::mosaic::ModelChunk>::Create(channel_.get(), cq, rpcmethod_ReceiveModelStream_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::mosaic::ModelChunk>* Mosaic::Stub::PrepareAsyncReceiveModelStreamRaw(::grpc::ClientContext* context, ::google::protobuf::Empty* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::mosaic::ModelChunk>::Create(channel_.get(), cq, rpcmethod_ReceiveModelStream_, context, response, false, nullptr);
}

Mosaic::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Mosaic_method_names[0],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< Mosaic::Service, ::mosaic::ImageAndTextChunk, ::mosaic::TextResponse>(
          [](Mosaic::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::mosaic::ImageAndTextChunk>* reader,
             ::mosaic::TextResponse* resp) {
               return service->ProcessImageAndText(ctx, reader, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Mosaic_method_names[1],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< Mosaic::Service, ::mosaic::ImageAndTextChunk, ::mosaic::TextResponse>(
          [](Mosaic::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::mosaic::ImageAndTextChunk>* reader,
             ::mosaic::TextResponse* resp) {
               return service->TrainModel(ctx, reader, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Mosaic_method_names[2],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< Mosaic::Service, ::google::protobuf::Empty, ::mosaic::ModelChunk>(
          [](Mosaic::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::Empty* req,
             ::grpc::ServerWriter<::mosaic::ModelChunk>* writer) {
               return service->SendModelStream(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Mosaic_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Mosaic::Service, ::google::protobuf::Empty, ::mosaic::IntValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Mosaic::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::Empty* req,
             ::mosaic::IntValue* resp) {
               return service->SendIntValue(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Mosaic_method_names[4],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< Mosaic::Service, ::mosaic::ModelChunk, ::google::protobuf::Empty>(
          [](Mosaic::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::mosaic::ModelChunk>* reader,
             ::google::protobuf::Empty* resp) {
               return service->ReceiveModelStream(ctx, reader, resp);
             }, this)));
}

Mosaic::Service::~Service() {
}

::grpc::Status Mosaic::Service::ProcessImageAndText(::grpc::ServerContext* context, ::grpc::ServerReader< ::mosaic::ImageAndTextChunk>* reader, ::mosaic::TextResponse* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Mosaic::Service::TrainModel(::grpc::ServerContext* context, ::grpc::ServerReader< ::mosaic::ImageAndTextChunk>* reader, ::mosaic::TextResponse* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Mosaic::Service::SendModelStream(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::grpc::ServerWriter< ::mosaic::ModelChunk>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Mosaic::Service::SendIntValue(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::mosaic::IntValue* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Mosaic::Service::ReceiveModelStream(::grpc::ServerContext* context, ::grpc::ServerReader< ::mosaic::ModelChunk>* reader, ::google::protobuf::Empty* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace mosaic

