// Number of Closed Islands — https://leetcode.com/problems/number-of-closed-islands/
// Count land (0) components that do not touch the border.
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& grid, int r, int c) {
    if (r < 0 || c < 0 || r >= static_cast<int>(grid.size())
        || c >= static_cast<int>(grid[0].size()) || grid[r][c] != 0) {
        return;
    }
    grid[r][c] = 1; // sink land
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}

int closedIsland(std::vector<std::vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    // eliminate islands touching border
    for (int r = 0; r < m; ++r) {
        dfs(grid, r, 0);
        dfs(grid, r, n - 1);
    }
    for (int c = 0; c < n; ++c) {
        dfs(grid, 0, c);
        dfs(grid, m - 1, c);
    }
    int count = 0;
    for (int r = 1; r < m - 1; ++r) {
        for (int c = 1; c < n - 1; ++c) {
            if (grid[r][c] == 0) {
                ++count;
                dfs(grid, r, c);
            }
        }
    }
    return count;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0},
    };
    std::cout << closedIsland(grid) << " (expected 2)\n";
    return 0;
}
