// Compilation Model — C++ basics
// Compile+link two TUs: main uses square declared in a header, defined elsewhere.
#include "math_ops.h"
#include <iostream>

int main() {
    std::cout << "square(5)=" << square(5) << '\n';
    std::cout << "Build: c++ -std=c++17 main.cpp math_ops.cpp -o compilation_model\n";
    return 0;
}
