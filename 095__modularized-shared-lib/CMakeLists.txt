##
## dependencies:
##
## capacitor --- 1x ----.
##        \              \
##         '--> warp -----o===> spaceship.exe
##                       /
##         navigation --'
##
##
##
## in a first approach build it modularized
##
## $ mkdir build && cd build
## $ export PREFIX="$(pwd)"
## $ cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ../capacitor_lib
## $ ninja
## $ ninja install
## $ rm CMakeCache.txt
## $ cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ../warp_lib
## $ ninja
## $ ninja install
## $ rm CMakeCache.txt
## $ cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ../navigation_lib
## $ ninja
## $ ninja install
## $ rm CMakeCache.txt
## $ cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ..
## $ ninja
## $ ninja install
## $ ./bin/spaceship.exe
##
## # FIXME
## $ mkdir build && cd build
## $ export PREFIX="$(pwd)"
## $ cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ..
## $ ninja
## $ ninja install
##
## FIXME: build topdown - in the source directory execute the following commands
## $ export PREFIX="$(pwd)"
## $ mkdir install
## $ mkdir build
## $ cmake -B $(pwd)/build -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX}/install -DCMAKE_PREFIX_PATH=${PREFIX}/build -S ..
## $ ninja
## $ ./spaceship.exe
##
## .a : use as is
## .so: use -DBUILD_SHARED_LIBS=ON
##
cmake_minimum_required(VERSION 3.9)
project(Spaceship VERSION 1.0.1 DESCRIPTION "my spaceship builder")
## set PROJECT_NAME, PROJECT_VERSION and PROJECT_DESCRIPTION


add_subdirectory(capacitor_lib)
add_subdirectory(warp_lib)
add_subdirectory(navigation_lib)


add_executable(spaceship.exe
  app/spaceship.cpp
)


## link libraries .a or .so
target_link_libraries(spaceship.exe
  libcapacitor
  libwarp
  libnavigation
)


## install
install(TARGETS spaceship.exe DESTINATION bin)
