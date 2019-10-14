#!/bin/bash -e
rm -rf build
mkdir -p build
cd build
cmake ..
make
./main.exe
