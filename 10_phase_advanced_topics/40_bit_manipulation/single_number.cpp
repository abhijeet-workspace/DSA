// Single Number — https://leetcode.com/problems/single-number/
// XOR all values; pairs cancel, unique remains.
#include <iostream>
#include <vector>

int singleNumber(const std::vector<int>& nums) {
    int x = 0;
    for (int n : nums)
        x ^= n;
    return x;
}

int main() {
    std::cout << singleNumber({2, 2, 1}) << " (expected 1)\n"
              << singleNumber({4, 1, 2, 1, 2}) << " (expected 4)\n"
              << singleNumber({1}) << " (expected 1)\n";
    return 0;
}
