## $ mkdir build
## $ cd build
## $ cmake -GNinja CMAKE_PREFIX_PATH=./install ..
## $ ninja
## $ ./spaceship.exe
##
cmake_minimum_required(VERSION 3.9)
project(Spaceship VERSION 1.0.1 DESCRIPTION "my spaceship builder")
## set PROJECT_NAME, PROJECT_VERSION and PROJECT_DESCRIPTION

add_subdirectory(engine_lib)
add_subdirectory(display_lib)
add_subdirectory(navigation_lib)

add_executable(spaceship.exe
  app/spaceship.cpp
)

target_link_libraries(spaceship.exe
  libdisplay
  libengine
  libnavigation
)
