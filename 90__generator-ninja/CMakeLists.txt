##  COMPILATION by foot
##
##  # Compile the .cpp file into a .o
##  $ g++ -c -I include/ src/ChuckNorris.cpp -o libchucknorris.o
##
##  # Create an archive containing the .o
##  $ ar cr libchucknorris.a libchucknorris.o
##
##  # Compile main.cpp into main.o
##  $ g++ -c -I include/ src/main.cpp -o main.o
##
##  # Tell g++ to link everything into an executable
##  $ g++ main.o libchucknorris.a -o cpp_demo
##
##  # Run the executable we've just built:
##  $./cpp_demo
##  Chuck Norris can slam a revolving door.
##
##
##
##  CMAKE
##
##  $ mkdir -p build/default
##  $ cd build/default
##  $ cmake -GNinja ../..
##
##
##
##  RESOURCE
##
##  https://dmerej.info/blog/post/chuck-norris-part-1-cmake-ninja
##  original example by Dimitri Merejkowsky
##
##  author: Lothar Rubusch

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11) # use C++11

project(ChuckNorris)


## libraries: chucknorrisLib
add_library( chucknorrisLib
  include/ChuckNorris.h
  src/ChuckNorris.cpp
)


## public includes for library: chucknorrisLib
##
## PRIVATE:   use the headers only for the specified target
## INTERFACE: use the headers only for the target's clients
## PUBLIC:    use the headers for the specified target and the target's clients
target_include_directories( chucknorrisLib
  PUBLIC "include"
)


## build: chuck.exe
add_executable(chuck.exe
  src/main.cpp
)


## link: chuck.exe and lib
target_link_libraries(chuck.exe chucknorrisLib)
