// Minimum Subset Sum Difference — teaching (same core as LC 1049)
#include <iostream>
#include <numeric>
#include <vector>

int minimumDifference(const std::vector<int>& nums) {
    const int total = std::accumulate(nums.begin(), nums.end(), 0);
    const int target = total / 2;
    std::vector<char> dp(static_cast<size_t>(target + 1), 0);
    dp[0] = 1;
    for (int x : nums) {
        for (int w = target; w >= x; --w) {
            if (dp[static_cast<size_t>(w - x)]) dp[static_cast<size_t>(w)] = 1;
        }
    }
    for (int w = target; w >= 0; --w) {
        if (dp[static_cast<size_t>(w)]) return total - 2 * w;
    }
    return total;
}

int main() {
    std::vector<int> nums{1, 6, 11, 5};
    std::cout << minimumDifference(nums) << " (expected 1)\n";
    return 0;
}
