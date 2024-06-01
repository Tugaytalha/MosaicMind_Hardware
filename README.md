# Setup Guide

**Note:** This code was tested on Raspberry Pi OS (64-bit). Compatibility with other platforms/versions is not guaranteed.

## Install Dependencies

### gRPC for C++
Install by following the instructions on this website: [gRPC C++ Quickstart](https://grpc.io/docs/languages/cpp/quickstart/)

**Note:** Depending on your Raspberry Pi model, compiling may take from several hours to almost an entire day. We have a build that works
on Raspberry Pi 3. You can download this build [from here](https://drive.google.com/drive/folders/1wNT5VdHWdcsYvGWe4A7uxwNhLR30y61z). After downloading,
just unzip it wherever you want on your computer and create and environment variable that holds the path to that unzipped directory (you can do that using the `export` command like shown in the gRPC website).
Don't forget to also add the `bin` directory within the installation directory to your PATH like shown in the gRPC website. For convenience, you may add these exports to your `.bashrc` (or equivalent).

> **Recommendation:** Choose an installation path other than the `.local` directory to make it easier to remove later.

### Python dependencies
You may install the Python related dependencies from [here](https://github.com/Tugaytalha/MosaicMind_AI).
- Download `install_dependencies.sh`.
- Follow the steps in the README. Change `source ~/.bashrc` depending on the shell you are using (or just restart the terminal).

**IMPORTANT:** Don't forget to activate the conda environment with the necessary dependencies before running the `receiver` program.

## Model File

There needs to be a model file named `model_scripted.pt`. This cannot be uploaded to GitHub due to its size. You can download this file [from here](https://drive.google.com/drive/folders/1wNT5VdHWdcsYvGWe4A7uxwNhLR30y61z).
This file needs the be in the `cmake/build` directory.

## Compilation
If you run this code on the Raspberry Pi, recompilation may not be necessary. You may skip to [running the program](#running-the-program). Compilation is done via:

```bash
make -j 4
```

This command will probably not work because you need to regenerate the CMake files. To do so:
1. Delete the contents of the build directory except for `receiver.cc`, `generate_caption.py` and `train_model.py`.
2. Inside the `build` directory, run:
```bash
cmake -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR ../..
```
Replace `$MY_INSTALL_DIR` with the name of the environment variable that holds the path to the gRPC installation on your computer.

After running the above command, run the previous two commands again:
```bash
make -j 4
```

## Running the program

Make sure all the devices with the IP addresses in the code are running the `receiver` program. Then run the program via the command:
```bash
./receiver
```
