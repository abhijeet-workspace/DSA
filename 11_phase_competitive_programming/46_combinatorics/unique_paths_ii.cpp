// Unique Paths II — LC 63
#include <iostream>
#include <vector>
int uniquePathsWithObstacles(std::vector<std::vector<int>> grid) {
    const int m = (int)grid.size(), n = (int)grid[0].size();
    std::vector<long long> dp(n, 0);
    dp[0] = grid[0][0] == 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1)
                dp[j] = 0;
            else if (j > 0)
                dp[j] += dp[j - 1];
        }
    }
    return (int)dp[n - 1];
}
int main() {
    std::cout << uniquePathsWithObstacles({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}) << " (expected 2)\n";
    return 0;
}
