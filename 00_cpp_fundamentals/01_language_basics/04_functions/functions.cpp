// Functions — C++ basics
// Define a small helper, call it from main, print the result.
#include <iostream>

int add(int a, int b) { // return sum of two ints
    return a + b;
}

int main() {
    std::cout << "Sum: " << add(2, 3) << std::endl; // call add
    return 0;
}
