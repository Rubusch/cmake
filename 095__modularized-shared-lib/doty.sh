#!/bin/bash -e
mkdir -p build && cd build

cmake --graphviz=dot/spaceship.dot ..

dotty dot/spaceship.dot
