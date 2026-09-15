// Longest Arithmetic Subsequence — https://leetcode.com/problems/longest-arithmetic-subsequence/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int longestArithSeqLength(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<std::unordered_map<int, int>> dp(n);
    int ans = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            const int d = nums[static_cast<size_t>(i)] - nums[static_cast<size_t>(j)];
            const int prev =
                dp[static_cast<size_t>(j)].count(d) ? dp[static_cast<size_t>(j)][d] : 1;
            dp[static_cast<size_t>(i)][d] = prev + 1;
            ans = std::max(ans, dp[static_cast<size_t>(i)][d]);
        }
    }
    return ans;
}

int main() {
    std::vector<int> nums{3, 6, 9, 12};
    std::cout << longestArithSeqLength(nums) << " (expected 4)\n";
    return 0;
}
