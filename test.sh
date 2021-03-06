#!/usr/bin/env bash

set -eu

(
    mkdir -p build
    cd build
    cmake ..
    make
)
infile=$1
./build/encode <$infile >out.bin || true
./build/decode <out.bin >out.txt || true
diff $infile out.txt
