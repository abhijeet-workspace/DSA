// Longest Increasing Path in a Matrix —
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#include <algorithm>
#include <iostream>
#include <vector>

int dfs(const std::vector<std::vector<int>>& matrix, int r, int c,
        std::vector<std::vector<int>>& memo) {
    if (memo[static_cast<size_t>(r)][static_cast<size_t>(c)] != 0)
        return memo[static_cast<size_t>(r)][static_cast<size_t>(c)];
    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};
    const int R = static_cast<int>(matrix.size());
    const int C = static_cast<int>(matrix[0].size());
    int best = 1;
    for (int k = 0; k < 4; ++k) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr < 0 || nc < 0 || nr >= R || nc >= C)
            continue;
        if (matrix[static_cast<size_t>(nr)][static_cast<size_t>(nc)] >
            matrix[static_cast<size_t>(r)][static_cast<size_t>(c)]) {
            best = std::max(best, 1 + dfs(matrix, nr, nc, memo));
        }
    }
    return memo[static_cast<size_t>(r)][static_cast<size_t>(c)] = best;
}

int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty())
        return 0;
    const int R = static_cast<int>(matrix.size());
    const int C = static_cast<int>(matrix[0].size());
    std::vector<std::vector<int>> memo(static_cast<size_t>(R),
                                       std::vector<int>(static_cast<size_t>(C), 0));
    int ans = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            ans = std::max(ans, dfs(matrix, i, j, memo));
    return ans;
}

int main() {
    std::cout << longestIncreasingPath({{9, 9, 4}, {6, 6, 8}, {2, 1, 1}}) << " (expected 4)\n";
    return 0;
}
