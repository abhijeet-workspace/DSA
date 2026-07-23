// Single Number — https://leetcode.com/problems/single-number/
// XOR all values; pairs cancel, unique remains.
#include <iostream>
#include <vector>

int singleNumber(const std::vector<int>& nums) {
    int x = 0;
    for (int n : nums) x ^= n;
    return x;
}

int main() {
    const std::vector<int> a = {4, 1, 2, 1, 2};
    std::cout << singleNumber(a) << " (expected 4)\n";
    return 0;
}
