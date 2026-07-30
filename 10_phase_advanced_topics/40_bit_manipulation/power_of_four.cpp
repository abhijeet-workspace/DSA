// Power of Four — https://leetcode.com/problems/power-of-four/
// Power of two whose single bit lies on an even index (mask 0x55555555).
#include <iostream>

bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
}

int main() {
    std::cout << std::boolalpha
              << isPowerOfFour(16) << " (expected true)\n"
              << isPowerOfFour(5) << " (expected false)\n"
              << isPowerOfFour(1) << " (expected true)\n";
    return 0;
}
