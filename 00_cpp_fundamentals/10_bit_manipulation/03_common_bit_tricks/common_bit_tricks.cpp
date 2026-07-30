// Common Bit Tricks — C++ fundamentals
// Parity, power-of-two, XOR swap, Kernighan popcount.
#include <iostream>

bool isOdd(int n) {
    return (n & 1) != 0;
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void xorSwap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // clear lowest set bit
        ++count;
    }
    return count;
}

int main() {
    std::cout << "5 odd? " << (isOdd(5) ? "yes" : "no") << "\n";
    std::cout << "4 odd? " << (isOdd(4) ? "yes" : "no") << "\n";

    std::cout << "16 power of two? " << (isPowerOfTwo(16) ? "yes" : "no") << "\n";
    std::cout << "18 power of two? " << (isPowerOfTwo(18) ? "yes" : "no") << "\n";

    int a = 3, b = 7;
    xorSwap(a, b);
    std::cout << "after xor swap: a=" << a << ", b=" << b << "\n";

    std::cout << "set bits in 15: " << countSetBits(15) << "\n";
    return 0;
}
