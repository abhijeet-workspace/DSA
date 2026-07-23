// Longest Increasing Path in a Matrix — https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// DFS + memo: longest strictly increasing path from each cell.
#include <algorithm>
#include <iostream>
#include <vector>

int dfs(const std::vector<std::vector<int>>& g, std::vector<std::vector<int>>& memo,
        int i, int j) {
    if (memo[static_cast<size_t>(i)][static_cast<size_t>(j)]) {
        return memo[static_cast<size_t>(i)][static_cast<size_t>(j)];
    }
    const int m = static_cast<int>(g.size());
    const int n = static_cast<int>(g[0].size());
    int best = 1;
    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};
    for (int k = 0; k < 4; ++k) {
        const int ni = i + dr[k];
        const int nj = j + dc[k];
        if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
            g[static_cast<size_t>(ni)][static_cast<size_t>(nj)] >
                g[static_cast<size_t>(i)][static_cast<size_t>(j)]) {
            best = std::max(best, 1 + dfs(g, memo, ni, nj));
        }
    }
    return memo[static_cast<size_t>(i)][static_cast<size_t>(j)] = best;
}

int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
    const int m = static_cast<int>(matrix.size());
    const int n = static_cast<int>(matrix[0].size());
    std::vector<std::vector<int>> memo(static_cast<size_t>(m),
                                       std::vector<int>(static_cast<size_t>(n), 0));
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = std::max(ans, dfs(matrix, memo, i, j));
        }
    }
    return ans;
}

int main() {
    const std::vector<std::vector<int>> a = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    std::cout << longestIncreasingPath(a) << " (expected 4)\n";
    return 0;
}
