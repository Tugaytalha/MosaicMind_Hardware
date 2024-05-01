#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define DIRECTORY_PATH "." // TODO: Change this to exact path of directory
#define COMMAND_MAX_LEN 512

void process_image(char *filename) {
    char command[COMMAND_MAX_LEN];
    snprintf(command, COMMAND_MAX_LEN, "python3 caption_generate.py %s", filename);
    system(command);
}

int is_png_file(char *filename) {
    char *ext = strrchr(filename, '.');
    if (ext != NULL && strcmp(ext, ".jpeg") == 0) {
        return 1;
    }
    return 0;
}

int main() {
    char directory_path[COMMAND_MAX_LEN];

    if (getcwd(directory_path, sizeof(directory_path)) == NULL) {
        perror("Error getting current directory");
        return EXIT_FAILURE;
    }

    while (1) {
        DIR *dir;
        struct dirent *ent;

        // Open directory
        if ((dir = opendir(directory_path)) != NULL) {
            // Process each file in directory
            while ((ent = readdir(dir)) != NULL) {
                // Check if file is a PNG image
                if (is_png_file(ent->d_name)) {
                    // Process image
                    char filepath[COMMAND_MAX_LEN];
                    snprintf(filepath, COMMAND_MAX_LEN, "%s/%s", directory_path, ent->d_name);
                    process_image(filepath);
                }
            }
            closedir(dir);
        } else {
            perror("Error opening directory");
            return EXIT_FAILURE;
        }
        sleep(10); // Sleep for 10 seconds
    }
    return EXIT_SUCCESS;
}
