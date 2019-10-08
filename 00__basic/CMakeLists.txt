## simple header
##
## build and run as follows:
## $ mkdir build
## $ cd build
## $ cmake ..
## $ make
## $ ./main.exe
##
################################################################################

## Basic
cmake_minimum_required (VERSION 2.6)
project (Basic)

## (opt) version number
set (Basic_VERSION_MAJOR 1)
set (Basic_VERSION_MINOR 0)

## build an executable: executable name, then sources
add_executable(main.exe main.cpp)
