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


cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11) # use C++11

project(ChuckNorris)


## libraries: sqlite3 (third party - IMPORTED)
##
## IMPORTED_LOCATION:              path to the lib.a file
## INTERFACE_INCLUDE_DIRECTORIES:  path to the sqlite3.h file(s)
add_library( sqlite3 STATIC IMPORTED)
set_target_properties( sqlite3
  PROPERTIES
  IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libsqlite3.a
  INTERFACE_INCLUDE_DIRECTORIES /usr/include
)


## libraries: chucknorrisLib
add_library( chucknorrisLib
  include/ChuckNorris.h
  src/ChuckNorris.cpp
)
target_include_directories( chucknorrisLib
  PUBLIC "include"
)

## build: lib with third party library
target_link_libraries(chucknorrisLib sqlite3)

## build: chuck.exe
add_executable(chuck.exe src/main.cpp)
target_link_libraries(chuck.exe chucknorrisLib)
