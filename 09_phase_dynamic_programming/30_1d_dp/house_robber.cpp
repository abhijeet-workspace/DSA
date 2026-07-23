// House Robber — https://leetcode.com/problems/house-robber/
// Max loot on a line; cannot rob two adjacent houses.
#include <iostream>
#include <vector>
#include <algorithm>

int rob(const std::vector<int>& nums) {
    int prev2 = 0; // best ending before previous
    int prev1 = 0; // best up to previous house
    for (int x : nums) {
        const int cur = std::max(prev1, prev2 + x); // skip vs take
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    std::cout << rob({1, 2, 3, 1}) << " (expected 4)\n"
              << rob({2, 7, 9, 3, 1}) << " (expected 12)\n";
    return 0;
}
