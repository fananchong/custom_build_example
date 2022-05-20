#!/bin/bash

set -ex

cur_dir=$(pwd)

rm -rf build temp bin
mkdir -p build temp bin
ls *.txt | grep -v "CMakeLists.txt" | xargs -i cp {} temp/{}.cpp
pushd build
cmake ..
make VERBOSE=1
make install
popd
pushd build/CMakeFiles/test.dir/temp/
ls *.o | xargs -i cp {} ${cur_dir}/bin/{}
popd
pushd ${cur_dir}/bin/
v=$(ls *.o)
for f in ${v[@]}; do
    mv ${f} $(echo ${f} | cut -d . -f 1,2)
done
popd
