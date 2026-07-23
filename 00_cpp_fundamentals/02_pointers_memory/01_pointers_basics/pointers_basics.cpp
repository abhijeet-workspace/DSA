// Pointers Basics — C++ fundamentals
// Show address-of, store address in a pointer, and dereference to read the value.
#include <iostream>

int main() {
    int a = 10; // stack int
    int* pA = &a; // pointer holds address of a

    std::cout << "Value: " << *pA << std::endl; // dereference to read a
    std::cout << "Address: " << pA << std::endl; // print stored address
    return 0;
}
