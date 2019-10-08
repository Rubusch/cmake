## simple header
##
## build and run as follows:
## $ mkdir build
## $ cd build
## $ cmake ../
## $ make
## $ ./main.exe
##
################################################################################

cmake_minimum_required (VERSION 2.6)
project (Basic)


include_directories("${PROJECT_SOURCE_DIR}/generator_dir" "${PROJECT_BINARY_DIR}/include")
add_subdirectory(generator_dir)


add_executable(main.exe main.cpp)
target_link_libraries(main.exe LibA)

## install
install(TARGETS main.exe DESTINATION bin)
