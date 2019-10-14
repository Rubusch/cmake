#!/bin/bash -e
rm -rf build
mkdir -p build
cd build
cmake -GNinja ..
ninja
./chuck.exe
