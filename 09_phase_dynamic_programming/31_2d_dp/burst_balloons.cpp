// Burst Balloons — https://leetcode.com/problems/burst-balloons/
// Max coins from bursting balloons; adjacent products score each burst.
#include <algorithm>
#include <iostream>
#include <vector>

int maxCoins(std::vector<int> nums) {
    nums.insert(nums.begin(), 1); // sentinel left wall
    nums.push_back(1); // sentinel right wall
    const int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0)); // dp[l][r]
    for (int len = 2; len < n; ++len) { // open interval length
        for (int l = 0; l + len < n; ++l) {
            const int r = l + len;
            for (int k = l + 1; k < r; ++k) { // last balloon burst in (l,r)
                dp[l][r] = std::max(dp[l][r],
                    nums[l] * nums[k] * nums[r] + dp[l][k] + dp[k][r]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    std::cout << maxCoins({3, 1, 5, 8}) << " (expected 167)\n";
    return 0;
}
