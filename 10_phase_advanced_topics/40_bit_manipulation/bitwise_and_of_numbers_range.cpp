// Bitwise AND of Numbers Range — https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Common prefix of left/right via simultaneous right shifts.
#include <iostream>

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        ++shift;
    }
    return left << shift;
}

int main() {
    std::cout << rangeBitwiseAnd(5, 7) << " (expected 4)\n"
              << rangeBitwiseAnd(0, 0) << " (expected 0)\n"
              << rangeBitwiseAnd(1, 2147483647) << " (expected 0)\n";
    return 0;
}
