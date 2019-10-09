## simple header
##
## build and run as follows:
## $ mkdir build
## $ cd build
## $ cmake -DCMAKE_INSTALL_PREFIX=./ ..
## $ make
## $ make install
## $ ./bin/main.exe
##
################################################################################

cmake_minimum_required (VERSION 2.6)
project (Basic)


#include_directories("${PROJECT_SOURCE_DIR}/generator_dir")
add_subdirectory(generator_dir)


add_executable(main.exe main.cpp)
#target_link_libraries(main.exe LibA)

## install
install(TARGETS main.exe DESTINATION bin)
