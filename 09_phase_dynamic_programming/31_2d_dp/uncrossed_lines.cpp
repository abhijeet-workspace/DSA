// Uncrossed Lines — https://leetcode.com/problems/uncrossed-lines/
#include <algorithm>
#include <iostream>
#include <vector>

int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
    const int n = static_cast<int>(nums1.size());
    const int m = static_cast<int>(nums2.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (nums1[static_cast<size_t>(i - 1)] == nums2[static_cast<size_t>(j - 1)]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    std::vector<int> a{1, 4, 2}, b{1, 2, 4};
    std::cout << maxUncrossedLines(a, b) << " (expected 2)\n";
    return 0;
}
