// Single Number II — https://leetcode.com/problems/single-number-ii/
// Bit counts % 3, or ones/twos FSM; every value thrice except one.
#include <iostream>
#include <vector>

int singleNumber(const std::vector<int>& nums) {
    int ones = 0;
    int twos = 0;
    for (int n : nums) {
        ones = (ones ^ n) & ~twos; // seen once (mod 3)
        twos = (twos ^ n) & ~ones; // seen twice (mod 3)
    }
    return ones; // thrice-seen bits cleared from both
}

int main() {
    std::cout << singleNumber({2, 2, 3, 2}) << " (expected 3)\n"
              << singleNumber({0, 1, 0, 1, 0, 1, 99}) << " (expected 99)\n";
    return 0;
}
