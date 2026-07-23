#!/bin/bash
set -e

echo "Creating build directory..."
mkdir -p build
cd build

echo "Configuring CMake..."
cmake ..

echo "Building project..."
cmake --build . --parallel 4

echo ""
echo "============================"
echo " Running Tests...           "
echo "============================"
ctest --output-on-failure

echo ""
echo "============================"
echo " Running Trading Engine...  "
echo "============================"
./TradingEngine
