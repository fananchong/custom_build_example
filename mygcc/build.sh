#!/bin/bash

cur_dir=$(pwd)

rm -rf ../build
mkdir -p ../build
pushd ../build
cmake ${cur_dir}
make clean
make
make install
popd
