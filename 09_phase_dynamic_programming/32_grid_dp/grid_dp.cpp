// Grid DP demos — Unique Paths (62), Min Path Sum (64), Maximal Square (221).
// Rolling 1D where possible; 2D for square side lengths.
#include <algorithm>
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

int minPathSum(const std::vector<std::vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    std::vector<int> dp(static_cast<size_t>(n), 0);
    dp[0] = grid[0][0];
    for (int j = 1; j < n; ++j) {
        dp[static_cast<size_t>(j)] =
            dp[static_cast<size_t>(j - 1)] + grid[0][static_cast<size_t>(j)];
    }
    for (int i = 1; i < m; ++i) {
        dp[0] += grid[static_cast<size_t>(i)][0];
        for (int j = 1; j < n; ++j) {
            dp[static_cast<size_t>(j)] =
                grid[static_cast<size_t>(i)][static_cast<size_t>(j)] +
                std::min(dp[static_cast<size_t>(j)], dp[static_cast<size_t>(j - 1)]);
        }
    }
    return dp[static_cast<size_t>(n - 1)];
}

int maximalSquare(const std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    const int m = static_cast<int>(matrix.size());
    const int n = static_cast<int>(matrix[0].size());
    std::vector<std::vector<int>> dp(static_cast<size_t>(m) + 1,
                                     std::vector<int>(static_cast<size_t>(n) + 1, 0));
    int maxSide = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (matrix[static_cast<size_t>(i - 1)][static_cast<size_t>(j - 1)] == '1') {
                dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    1 + std::min({dp[static_cast<size_t>(i - 1)][static_cast<size_t>(j)],
                                  dp[static_cast<size_t>(i)][static_cast<size_t>(j - 1)],
                                  dp[static_cast<size_t>(i - 1)][static_cast<size_t>(j - 1)]});
                maxSide = std::max(maxSide, dp[static_cast<size_t>(i)][static_cast<size_t>(j)]);
            }
        }
    }
    return maxSide * maxSide;
}

int main() {
    std::cout << uniquePaths(3, 7) << " (expected 28)\n";
    const std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    std::cout << minPathSum(grid) << " (expected 7)\n";
    const std::vector<std::vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    std::cout << maximalSquare(matrix) << " (expected 4)\n";
    return 0;
}
