# libCC

A simple cross-platform game engine written in C++

- dependencies are keep to the minimum
- does not use exceptions or streams
- targets a common subset of OpenGL (webGL, gles2 and desktop)

# Build Instructions

## Windows and Linux

Generate dependencies (see deps/README)

### Build the library

```bash
mkdir build
cd build
cmake -DCC_PLATFORM=<LINUX|WINDOWS> -DCMAKE_BUILD_TYPE=<Debug|Release> ..
make
```

## Emscripten (on Linux)

### Generate dependencies and activate sdk (see deps/README)

### Build the library

```bash
mkdir build
cd build
source ../deps/sdks/linux/emsdk_portable/emsdk_env.sh
cmake -DCC_PLATFORM=<EMSC> -DCMAKE_BUILD_TYPE=<Debug|Release>
  -DCMAKE_TOOLCHAIN_FILE=../deps/sdks/linux/emscriptenToolchain.cmake ..
make
```
