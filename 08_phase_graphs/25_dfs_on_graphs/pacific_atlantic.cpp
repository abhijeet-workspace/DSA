// Pacific Atlantic Water Flow — https://leetcode.com/problems/pacific-atlantic-water-flow/
// Cells that can reach both oceans; DFS inland from borders (non-decreasing height).
#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& heights, int r, int c, int prev,
         std::vector<std::vector<bool>>& visited) {
    if (r < 0 || c < 0 || r >= static_cast<int>(heights.size())
        || c >= static_cast<int>(heights[0].size()) || visited[r][c]
        || heights[r][c] < prev) {
        return;
    }
    visited[r][c] = true;
    const int h = heights[r][c];
    dfs(heights, r + 1, c, h, visited);
    dfs(heights, r - 1, c, h, visited);
    dfs(heights, r, c + 1, h, visited);
    dfs(heights, r, c - 1, h, visited);
}

std::vector<std::vector<int>> pacificAtlantic(const std::vector<std::vector<int>>& heights) {
    if (heights.empty() || heights[0].empty()) {
        return {};
    }
    const int m = static_cast<int>(heights.size());
    const int n = static_cast<int>(heights[0].size());
    std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n));
    std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n));

    for (int i = 0; i < m; ++i) {
        dfs(heights, i, 0, heights[i][0], pacific);           // left = Pacific
        dfs(heights, i, n - 1, heights[i][n - 1], atlantic);  // right = Atlantic
    }
    for (int j = 0; j < n; ++j) {
        dfs(heights, 0, j, heights[0][j], pacific);           // top = Pacific
        dfs(heights, m - 1, j, heights[m - 1][j], atlantic);  // bottom = Atlantic
    }

    std::vector<std::vector<int>> result;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push_back({i, j});
            }
        }
    }
    return result;
}

int main() {
    const std::vector<std::vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4},
    };
    auto res = pacificAtlantic(heights);
    std::cout << "cells=" << res.size() << " (expected 7)\n";
    for (const auto& p : res) {
        std::cout << "[" << p[0] << "," << p[1] << "] ";
    }
    std::cout << "\n";
    return 0;
}
