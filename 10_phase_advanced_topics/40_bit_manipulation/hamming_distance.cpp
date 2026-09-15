// Hamming Distance — https://leetcode.com/problems/hamming-distance/
// popcount(x ^ y) via Brian Kernighan.
#include <iostream>

int hammingDistance(int x, int y) {
    int n = x ^ y;
    int ans = 0;
    while (n) {
        n &= n - 1;
        ++ans;
    }
    return ans;
}

int main() {
    std::cout << hammingDistance(1, 4) << " (expected 1)\n"
              << hammingDistance(3, 1) << " (expected 1)\n";
    return 0;
}
