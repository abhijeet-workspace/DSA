// Single Number III — https://leetcode.com/problems/single-number-iii/
// Total XOR = a^b; lowest set bit partitions into two XOR groups.
#include <iostream>
#include <vector>

std::vector<int> singleNumber(const std::vector<int>& nums) {
    int x = 0;
    for (int n : nums) x ^= n;
    int mask = x & -x;  // lowest set bit
    int a = 0, b = 0;
    for (int n : nums) {
        if (n & mask) a ^= n;
        else b ^= n;
    }
    return {a, b};
}

int main() {
    auto v = singleNumber({1, 2, 1, 3, 2, 5});
    std::cout << v[0] << " " << v[1] << " (expected 3 5 or 5 3)\n";
    return 0;
}
