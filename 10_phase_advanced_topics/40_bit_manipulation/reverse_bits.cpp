// Reverse Bits — https://leetcode.com/problems/reverse-bits/
// Build result by shifting in n's LSB 32 times (do not early-stop).
#include <iostream>
#include <cstdint>

std::uint32_t reverseBits(std::uint32_t n) {
    std::uint32_t res = 0;
    for (int i = 0; i < 32; ++i) {
        res = (res << 1) | (n & 1u);
        n >>= 1;
    }
    return res;
}

int main() {
    std::cout << reverseBits(43261596) << " (expected 964176192)\n"
              << reverseBits(0) << " (expected 0)\n";
    return 0;
}
