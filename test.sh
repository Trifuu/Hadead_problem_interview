#!/usr/bin/env bash

set -eu

(
    mkdir -p build
    cd build
    cmake ..
    make
)
infile=$1
./build/encode <$infile >out.bin
./build/decode <out.bin >out.txt
diff $infile out.txt
