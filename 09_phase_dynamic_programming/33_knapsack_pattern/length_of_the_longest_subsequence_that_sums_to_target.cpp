// Length of the Longest Subsequence That Sums to Target —
// https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/
#include <algorithm>
#include <iostream>
#include <vector>

int lengthOfLongestSubsequence(std::vector<int>& nums, int target) {
    const int INF = -1e9;
    std::vector<int> dp(static_cast<size_t>(target + 1), INF);
    dp[0] = 0;
    for (int x : nums) {
        for (int s = target; s >= x; --s) {
            if (dp[static_cast<size_t>(s - x)] != INF) {
                dp[static_cast<size_t>(s)] =
                    std::max(dp[static_cast<size_t>(s)], dp[static_cast<size_t>(s - x)] + 1);
            }
        }
    }
    return dp[static_cast<size_t>(target)] < 0 ? -1 : dp[static_cast<size_t>(target)];
}

int main() {
    std::vector<int> nums{1, 2, 3, 4, 5};
    std::cout << lengthOfLongestSubsequence(nums, 9) << " (expected 3)\n";
    return 0;
}
