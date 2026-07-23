// Target Sum — https://leetcode.com/problems/target-sum/
// Assign +/- to each num; count ways to reach target (subset-sum DP).
#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>

int findTargetSumWays(const std::vector<int>& nums, int target) {
    const int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 != 0 || std::abs(target) > sum) {
        return 0; // impossible partition
    }
    const int need = (sum + target) / 2; // positive-subset sum
    std::vector<int> dp(static_cast<size_t>(need) + 1, 0);
    dp[0] = 1;
    for (int x : nums) {
        for (int s = need; s >= x; --s) { // 0/1 knapsack backward
            dp[static_cast<size_t>(s)] += dp[static_cast<size_t>(s - x)];
        }
    }
    return dp[static_cast<size_t>(need)];
}

int main() {
    const std::vector<int> a = {1, 1, 1, 1, 1};
    std::cout << findTargetSumWays(a, 3) << " (expected 5)\n";
    return 0;
}
