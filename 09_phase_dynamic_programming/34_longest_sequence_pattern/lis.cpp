// Longest Increasing Subsequence — https://leetcode.com/problems/longest-increasing-subsequence/
// O(N^2) DP: dp[i] = best LIS ending at i. (O(N log N) patience sort as follow-up.)
#include <algorithm>
#include <iostream>
#include <vector>

int lengthOfLIS(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    if (n == 0) {
        return 0;
    }
    std::vector<int> dp(static_cast<size_t>(n), 1);
    int best = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[static_cast<size_t>(i)] > nums[static_cast<size_t>(j)]) {
                dp[static_cast<size_t>(i)] = std::max(dp[static_cast<size_t>(i)],
                                                      dp[static_cast<size_t>(j)] + 1);
            }
        }
        best = std::max(best, dp[static_cast<size_t>(i)]);
    }
    return best;
}

int main() {
    std::cout << lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) << " (expected 4)\n"
              << lengthOfLIS({0, 1, 0, 3, 2, 3}) << " (expected 4)\n";
    return 0;
}
