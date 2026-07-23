// Number of 1 Bits — https://leetcode.com/problems/number-of-1-bits/
// Brian Kernighan: n &= n-1 clears the lowest set bit.
#include <iostream>
#include <cstdint>

int hammingWeight(std::uint32_t n) {
    int c = 0;
    while (n) {
        n &= n - 1;
        ++c;
    }
    return c;
}

int main() {
    std::cout << hammingWeight(11) << " (expected 3)\n"
              << hammingWeight(128) << " (expected 1)\n";
    return 0;
}
