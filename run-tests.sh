#!/bin/sh
# Build every source file plus the tests into one binary and run it.
set -e
mkdir -p build
c++ -std=c++17 -Wall -Iinclude src/*.cpp tests/*.cpp -o build/run_tests
./build/run_tests
