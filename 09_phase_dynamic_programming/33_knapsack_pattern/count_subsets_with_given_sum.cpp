// Count Subsets With Given Sum — teaching (Target Sum / 494 pattern)
#include <iostream>
#include <vector>

int countSubsets(const std::vector<int>& nums, int target) {
    std::vector<int> dp(static_cast<size_t>(target + 1), 0);
    dp[0] = 1;
    for (int x : nums) {
        for (int s = target; s >= x; --s) {
            dp[static_cast<size_t>(s)] += dp[static_cast<size_t>(s - x)];
        }
    }
    return dp[static_cast<size_t>(target)];
}

int main() {
    std::vector<int> nums{1, 1, 2, 3};
    std::cout << countSubsets(nums, 4) << " (expected 3)\n";
    return 0;
}
