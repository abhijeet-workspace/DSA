// Number of Enclaves — https://leetcode.com/problems/number-of-enclaves/
// Count land cells (1) that cannot walk off the boundary (4-dir).
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& grid, int r, int c) {
    const int R = static_cast<int>(grid.size());
    const int C = static_cast<int>(grid[0].size());
    if (r < 0 || c < 0 || r >= R || c >= C ||
        grid[static_cast<size_t>(r)][static_cast<size_t>(c)] != 1)
        return;
    grid[static_cast<size_t>(r)][static_cast<size_t>(c)] = 0;
    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}

int numEnclaves(std::vector<std::vector<int>> grid) {
    const int R = static_cast<int>(grid.size());
    const int C = static_cast<int>(grid[0].size());
    for (int i = 0; i < R; ++i) {
        dfs(grid, i, 0);
        dfs(grid, i, C - 1);
    }
    for (int j = 0; j < C; ++j) {
        dfs(grid, 0, j);
        dfs(grid, R - 1, j);
    }
    int count = 0;
    for (const auto& row : grid)
        for (int x : row)
            count += x;
    return count;
}

int main() {
    std::cout << numEnclaves({{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}})
              << " (expected 3)\n";
    return 0;
}
