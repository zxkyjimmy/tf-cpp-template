# tf-cpp-template
A simple template to develop tensorflow c++ application

## Requirements
- GCC
- Bazel 0.16.1
- Tensorflow 1.10.0
- (Optional) Cuda and cuDNN


## Building and Runing

### Clone & configure
Clone the repository and configure the building:
```bash
$ git clone https://github.com/zxkyjimmy/tf-cpp-template
$ cd tf-cpp-template
$ ./configure
```
Refer to [tensorflow official](https://www.tensorflow.org/install/install_sources) to know how to set `./configure`.

### Build
```bash
$ bazel build //example:example
```

### Run
```bash
$ bazel-bin/example/example
```


## Template

### example
- base on tensorflow [C++ API Guide](https://www.tensorflow.org/api_guides/cc/guide)

## If you would like to update tensorflow version

Please abjust the following files:
- `configure`
- `configure.py`
- `WORKSPACE`
- `tools/bazel.rc`
