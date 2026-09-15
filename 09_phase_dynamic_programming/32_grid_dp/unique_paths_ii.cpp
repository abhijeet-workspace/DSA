// Unique Paths II — https://leetcode.com/problems/unique-paths-ii/
// Grid DP with obstacles; 1D roll: dp[j] += dp[j-1], zero on obstacle.
#include <iostream>
#include <vector>

int uniquePathsWithObstacles(const std::vector<std::vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) {
        return 0;
    }
    const int m = static_cast<int>(obstacleGrid.size());
    const int n = static_cast<int>(obstacleGrid[0].size());
    std::vector<long long> dp(static_cast<size_t>(n), 0);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[static_cast<size_t>(i)][static_cast<size_t>(j)] == 1) {
                dp[static_cast<size_t>(j)] = 0; // blocked
            } else if (j > 0) {
                dp[static_cast<size_t>(j)] += dp[static_cast<size_t>(j - 1)];
            }
        }
    }
    return static_cast<int>(dp[static_cast<size_t>(n - 1)]);
}

int main() {
    std::cout << uniquePathsWithObstacles({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}) << " (expected 2)\n"
              << uniquePathsWithObstacles({{0, 1}, {0, 0}}) << " (expected 1)\n";
    return 0;
}
