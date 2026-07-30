// Power of Two — https://leetcode.com/problems/power-of-two/
// Positive n with exactly one set bit: n & (n-1) == 0.
#include <iostream>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    std::cout << std::boolalpha
              << isPowerOfTwo(1) << " (expected true)\n"
              << isPowerOfTwo(16) << " (expected true)\n"
              << isPowerOfTwo(3) << " (expected false)\n";
    return 0;
}
