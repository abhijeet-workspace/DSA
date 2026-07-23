// Multi-file Demo (main) — basic practice
// Call helpers declared in my_function.h from a separate translation unit.
#include <iostream>
#include "my_function.h"

int main() {
    sayHello(); // defined in my_function.cpp
    int value = printSumOfTwoNumber(20, 30); // cross-file call
    std::cout << "Sum of two number: " << value << std::endl;
    return 0;
}
