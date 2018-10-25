# Build instructions

### Build the library see
see libCC/README.md

## Emscripten (on Linux)
mkdir build
cd build
cp -r ../data .
source ../../../deps/sdks/linux/emsdk_portable/emsdk_env.sh
cmake -DCC_PLATFORM=EMSC -DCMAKE_BUILD_TYPE=<Debug|Release>
  -DCMAKE_TOOLCHAIN_FILE=../../../deps/sdks/linux/emscriptenToolchain.cmake ..
make

## Other platforms
mkdir build
cd build
cmake -DCC_PLATFORM=<LINUX|WINDOWS> -DCMAKE_BUILD_TYPE=<Debug|Release> ..
make
