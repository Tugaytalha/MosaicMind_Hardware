# Setup Guide

**Note:** This code was tested on Raspberry Pi OS (64-bit). Compatibility with other platforms/versions is not guaranteed.
**Note:** To be able to receive/send data from/to mobile devices and the main server, they need to be connected to the same network.

## Install Dependencies

### gRPC for C++
Install by following the instructions on this website: [gRPC C++ Quickstart](https://grpc.io/docs/languages/cpp/quickstart/)

**Note:** Depending on your Raspberry Pi model, compiling may take from several hours to almost an entire day. We have a build that works
on Raspberry Pi 3. If you create an issue on GitHub, we may reach out to you with the zip file.

> **Recommendation:** Choose an installation path other than the `.local` directory to make it easier to remove later.

### Python dependencies
You may install the Python related dependencies from [here](https://github.com/Tugaytalha/MosaicMind_AI).
- Download `install_dependencies.sh`.
- Follow the steps in the README. Change `source ~/.bashrc` depending on the shell you are using (or just restart the terminal).

Make sure to have the conda environment with the necessary dependencies activated before running the program.

## Model File

There needs to be a model file named `model_scripted.pt.` This cannot be uploaded to GitHub due to its size. You can request this file by opening an issue on the GitHub page.

## Compilation
If you run this code on the Raspberry Pi, recompilation may not be necessary. You may skip to [running the program](#running-the-program). Compilation is done via:

```bash
make -j 4
```

This command will probably not work because you need to regenerate the CMake files. To do so:
1. Delete the contents of the `build` directory EXCEPT FOR `receiver.cc`, `word_to_idx.txt`, `generate_caption.py` and `train_model.py`.
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

Make sure . Then run the program via the command:
```bash
./receiver
```
