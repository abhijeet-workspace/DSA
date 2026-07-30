// Bitwise Operators — C++ fundamentals
// Show &, |, ^, ~, <<, >> on small integers.
#include <iostream>

int main() {
    int a = 5; // 0101
    int b = 3; // 0011

    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "a & b  = " << (a & b) << "\n";   // 0001 → 1
    std::cout << "a | b  = " << (a | b) << "\n";   // 0111 → 7
    std::cout << "a ^ b  = " << (a ^ b) << "\n";   // 0110 → 6
    std::cout << "~a     = " << (~a) << "\n";      // flips all bits
    std::cout << "a << 1 = " << (a << 1) << "\n";  // 1010 → 10
    std::cout << "a >> 1 = " << (a >> 1) << "\n";  // 0010 → 2
    return 0;
}
