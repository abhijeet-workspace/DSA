// Longest Increasing Path in a Matrix — LeetCode 329
#include <algorithm>
#include <iostream>
#include <vector>

int dfs(int i, int j, const std::vector<std::vector<int>>& m, std::vector<std::vector<int>>& memo) {
    if (memo[static_cast<size_t>(i)][static_cast<size_t>(j)])
        return memo[static_cast<size_t>(i)][static_cast<size_t>(j)];
    static const int di[4] = {1, -1, 0, 0};
    static const int dj[4] = {0, 0, 1, -1};
    int best = 1;
    int R = static_cast<int>(m.size()), C = static_cast<int>(m[0].size());
    for (int d = 0; d < 4; ++d) {
        int ni = i + di[d], nj = j + dj[d];
        if (ni >= 0 && nj >= 0 && ni < R && nj < C &&
            m[static_cast<size_t>(ni)][static_cast<size_t>(nj)] >
                m[static_cast<size_t>(i)][static_cast<size_t>(j)])
            best = std::max(best, 1 + dfs(ni, nj, m, memo));
    }
    return memo[static_cast<size_t>(i)][static_cast<size_t>(j)] = best;
}

int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
    int R = static_cast<int>(matrix.size()), C = static_cast<int>(matrix[0].size());
    std::vector<std::vector<int>> memo(static_cast<size_t>(R),
                                       std::vector<int>(static_cast<size_t>(C), 0));
    int ans = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            ans = std::max(ans, dfs(i, j, matrix, memo));
    return ans;
}

int main() {
    std::cout << longestIncreasingPath({{9, 9, 4}, {6, 6, 8}, {2, 1, 1}}) << " (expected 4)\n";
    return 0;
}
