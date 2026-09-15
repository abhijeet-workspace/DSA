// Maximal Square — https://leetcode.com/problems/maximal-square/
#include <algorithm>
#include <iostream>
#include <vector>

int maximalSquare(std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;
    const int m = static_cast<int>(matrix.size());
    const int n = static_cast<int>(matrix[0].size());
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    int best = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (matrix[static_cast<size_t>(i - 1)][static_cast<size_t>(j - 1)] == '1') {
                dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                best = std::max(best, dp[i][j]);
            }
        }
    }
    return best * best;
}

int main() {
    std::vector<std::vector<char>> m{{'1', '0', '1', '0', '0'},
                                     {'1', '0', '1', '1', '1'},
                                     {'1', '1', '1', '1', '1'},
                                     {'1', '0', '0', '1', '0'}};
    std::cout << maximalSquare(m) << " (expected 4)\n";
    return 0;
}
