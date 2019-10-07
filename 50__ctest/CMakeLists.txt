## simple header
##
## build and run as follows:
## $ mkdir build && cd build
## $ cmake -DCMAKE_INSTALL_PREFIX=./ ..
## $ make
## $ make install
## $ ./bin/main.exe
##
################################################################################

## 1. project
cmake_minimum_required (VERSION 2.6)
project(Basic)

## 2. ctest (do not include ctest before project)
include(CTest)

## (opt) version number
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

## 3. includes
## add top level of include directories
include_directories ("${PROJECT_SOURCE_DIR}/include")


## 4. what is build (lib/exe)
## build an executable: executable name, and link sources
add_executable(main.exe main.cpp src/a.cpp)

## 5. installer
install(TARGETS main.exe DESTINATION bin)
install(FILES include/a.h DESTINATION include)
