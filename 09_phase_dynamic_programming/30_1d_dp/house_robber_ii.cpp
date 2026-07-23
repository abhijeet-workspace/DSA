// House Robber II — https://leetcode.com/problems/house-robber-ii/
// Circular street: first and last adjacent; max of two linear ranges.
#include <iostream>
#include <vector>
#include <algorithm>

int robLinear(const std::vector<int>& nums, int L, int R) {
    int prev2 = 0;
    int prev1 = 0;
    for (int i = L; i <= R; ++i) {
        const int cur = std::max(prev1, prev2 + nums[static_cast<size_t>(i)]);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int rob(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    if (n == 1) {
        return nums[0];
    }
    // exclude last OR exclude first
    return std::max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
}

int main() {
    std::cout << rob({2, 3, 2}) << " (expected 3)\n"
              << rob({1, 2, 3, 1}) << " (expected 4)\n";
    return 0;
}
