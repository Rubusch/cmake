##
## in the source directory execute the following commands
## $ export PREFIX="$(pwd)/install"
## $ mkdir install
## $ mkdir build
## $ cmake -B $(pwd)/build -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} -DCMAKE_PREFIX_PATH=${PREFIX} -S $(pwd)
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
