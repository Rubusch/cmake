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
test -d "${WHERE}/build" && rm -rf "${WHERE}/build"


## build top-down
mkdir "${WHERE}/build"
pushd $WHERE/build &> /dev/null
export PREFIX="$(pwd)"
cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ..
ninja
ninja install


## build piece by piece...
# mkdir "${WHERE}/build"
# pushd $WHERE/build &> /dev/null
# export PREFIX="$(pwd)"
# cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ../engine_lib
# ninja
# ninja install
# rm CMakeCache.txt
# cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ../display_lib
# ninja
# ninja install
# rm CMakeCache.txt
# cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ../navigation_lib
# ninja
# ninja install
# rm CMakeCache.txt
# cmake -GNinja -DCMAKE_INSTALL_PREFIX=${PREFIX} ..
# ninja
# ninja install

./bin/spaceship.exe

popd &> /dev/null
echo
echo "build.sh - READY."
