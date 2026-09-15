// Delete and Earn — https://leetcode.com/problems/delete-and-earn/
// Bucket points by value; house-robber DP on adjacent values.
#include <algorithm>
#include <iostream>
#include <vector>

int deleteAndEarn(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    const int maxV = *std::max_element(nums.begin(), nums.end());
    std::vector<int> points(static_cast<size_t>(maxV + 1), 0);
    for (int x : nums) {
        points[static_cast<size_t>(x)] += x;
    }
    int prev2 = 0; // best for values up to i-2
    int prev1 = 0; // best for values up to i-1
    for (int i = 0; i <= maxV; ++i) {
        const int cur = std::max(prev1, prev2 + points[static_cast<size_t>(i)]);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    std::cout << deleteAndEarn({3, 4, 2}) << " (expected 6)\n"
              << deleteAndEarn({2, 2, 3, 3, 3, 4}) << " (expected 9)\n";
    return 0;
}
