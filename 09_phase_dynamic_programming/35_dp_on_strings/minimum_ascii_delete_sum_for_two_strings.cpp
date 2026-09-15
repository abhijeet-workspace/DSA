// Minimum ASCII Delete Sum for Two Strings — https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int minimumDeleteSum(std::string s1, std::string s2) {
    const int n = static_cast<int>(s1.size()), m = static_cast<int>(s2.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) dp[i][0] = dp[i - 1][0] + s1[static_cast<size_t>(i - 1)];
    for (int j = 1; j <= m; ++j) dp[0][j] = dp[0][j - 1] + s2[static_cast<size_t>(j - 1)];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[static_cast<size_t>(i - 1)] == s2[static_cast<size_t>(j - 1)]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min(dp[i - 1][j] + s1[static_cast<size_t>(i - 1)],
                                    dp[i][j - 1] + s2[static_cast<size_t>(j - 1)]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    std::cout << minimumDeleteSum("sea", "eat") << " (expected 231)\n";
    return 0;
}
