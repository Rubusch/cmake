#!/bin/bash -e

cmake --graphviz=dot/spaceship.dot

dotty dot/spaceship.dot
