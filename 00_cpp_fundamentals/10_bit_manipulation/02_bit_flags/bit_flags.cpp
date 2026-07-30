// Bit Flags — C++ fundamentals
// Get, set, clear, and toggle a bit at position k using masks.
#include <iostream>

bool getBit(unsigned n, int k) {
    return (n & (1u << k)) != 0;
}

unsigned setBit(unsigned n, int k) {
    return n | (1u << k);
}

unsigned clearBit(unsigned n, int k) {
    return n & ~(1u << k);
}

unsigned toggleBit(unsigned n, int k) {
    return n ^ (1u << k);
}

int main() {
    unsigned n = 0b1010; // 10 decimal

    std::cout << "n = " << n << "\n";
    std::cout << "get bit 1: " << getBit(n, 1) << "\n";       // 1
    std::cout << "set bit 0: " << setBit(n, 0) << "\n";       // 11 (1011)
    std::cout << "clear bit 3: " << clearBit(n, 3) << "\n";   // 2 (0010)
    std::cout << "toggle bit 1: " << toggleBit(n, 1) << "\n"; // 8 (1000)
    return 0;
}
