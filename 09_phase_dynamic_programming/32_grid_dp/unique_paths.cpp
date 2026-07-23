// Unique Paths — https://leetcode.com/problems/unique-paths/
// Robot right/down only; 1D DP: dp[j] += dp[j-1] per row.
#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
    std::vector<int> dp(static_cast<size_t>(n), 1);
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[static_cast<size_t>(j)] += dp[static_cast<size_t>(j - 1)];
        }
    }
    return dp[static_cast<size_t>(n - 1)];
}

int main() {
    std::cout << uniquePaths(3, 7) << " (expected 28)\n"
              << uniquePaths(3, 2) << " (expected 3)\n";
    return 0;
}
