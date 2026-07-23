// Maximum Subarray — https://leetcode.com/problems/maximum-subarray/
// Contiguous subarray with the largest sum; return that sum.
#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(const std::vector<int>& nums) {
    int best = nums[0]; // global max sum
    int cur = nums[0]; // best ending here
    for (size_t i = 1; i < nums.size(); ++i) {
        cur = std::max(nums[i], cur + nums[i]); // restart or extend
        best = std::max(best, cur);
    }
    return best;
}

int main() {
    std::cout << maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << " (expected 6)\n"
              << maxSubArray({1}) << " (expected 1)\n"
              << maxSubArray({5, 4, -1, 7, 8}) << " (expected 23)\n";
    return 0;
}
