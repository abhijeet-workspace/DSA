// Partition Equal Subset Sum — https://leetcode.com/problems/partition-equal-subset-sum/
// 0/1 knapsack: can a subset sum to total/2? Descending capacity loop.
#include <iostream>
#include <numeric>
#include <vector>

bool canPartition(const std::vector<int>& nums) {
    const int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
        return false;
    }
    const int target = sum / 2;
    std::vector<char> dp(static_cast<size_t>(target) + 1, 0);
    dp[0] = 1;
    for (int x : nums) {
        for (int s = target; s >= x; --s) {
            dp[static_cast<size_t>(s)] =
                dp[static_cast<size_t>(s)] || dp[static_cast<size_t>(s - x)];
        }
    }
    return static_cast<bool>(dp[static_cast<size_t>(target)]);
}

int main() {
    std::cout << std::boolalpha
              << canPartition({1, 5, 11, 5}) << " (expected true)\n"
              << canPartition({1, 2, 3, 5}) << " (expected false)\n";
    return 0;
}
