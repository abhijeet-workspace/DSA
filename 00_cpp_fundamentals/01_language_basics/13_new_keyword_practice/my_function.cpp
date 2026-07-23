// Multi-file Demo (my_function) — basic practice
// Definitions matching prototypes in my_function.h.
#include <iostream>
#include "my_function.h"

void sayHello() {
    std::cout << "Hello from a separate file!" << std::endl; // print greeting
}

int printSumOfTwoNumber(int num1, int num2) {
    return num1 + num2; // return sum of args
}
