#!/bin/bash -e

die()
{
    echo "$@"
    exit 0
}

WHERE=$(dirname $0)
WHERE=$(readlink -f $WHERE)
echo $WHERE
test -z "${WHERE}" && die "script location was / ??!!!"


## build top-down
test -d "${WHERE}/build" && rm -rf "${WHERE}/build"
mkdir "${WHERE}/build"
pushd $WHERE/build &> /dev/null
export PREFIX="$(pwd)"
cmake -DCMAKE_INSTALL_PREFIX=${PREFIX} ..
make
make install
./bin/spaceship.exe
popd &> /dev/null

sleep 1

test -d "${WHERE}/build" && rm -rf "${WHERE}/build"
mkdir "${WHERE}/build"
pushd $WHERE/build &> /dev/null
export PREFIX="$(pwd)"
cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ..
ninja
ninja install
./bin/spaceship.exe
popd &> /dev/null

sleep 1

## build piece by piece...
test -d "${WHERE}/build" && rm -rf "${WHERE}/build"
mkdir "${WHERE}/build"
pushd $WHERE/build &> /dev/null
export PREFIX="$(pwd)"
cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ../capacitor_lib
ninja
ninja install
rm CMakeCache.txt
cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ../warp_lib
ninja
ninja install
rm CMakeCache.txt
cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ../navigation_lib
ninja
ninja install
rm CMakeCache.txt
cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ..
ninja
ninja install
./bin/spaceship.exe
popd &> /dev/null

sleep 1

## build piece by piece...
test -d "${WHERE}/build" && rm -rf "${WHERE}/build"
mkdir "${WHERE}/build"
pushd $WHERE/build &> /dev/null
export PREFIX="$(pwd)"
cmake -DCMAKE_INSTALL_PREFIX=${PREFIX} ../capacitor_lib
make
make install
rm CMakeCache.txt
cmake -DCMAKE_INSTALL_PREFIX=${PREFIX} ../warp_lib
make
make install
rm CMakeCache.txt
cmake -DCMAKE_INSTALL_PREFIX=${PREFIX} ../navigation_lib
make
make install
rm CMakeCache.txt
cmake -DCMAKE_INSTALL_PREFIX=${PREFIX} ..
make
make install
./bin/spaceship.exe
popd &> /dev/null

echo
echo "build.sh - READY."
