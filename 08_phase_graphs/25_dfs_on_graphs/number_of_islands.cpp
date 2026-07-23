// Number of Islands — https://leetcode.com/problems/number-of-islands/
// Count 4-connected components of '1' in a char grid.
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<char>>& grid, int r, int c) {
    if (r < 0 || c < 0 || r >= static_cast<int>(grid.size())
        || c >= static_cast<int>(grid[0].size()) || grid[r][c] == '0') {
        return;
    }
    grid[r][c] = '0'; // sink visited land
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}

int numIslands(std::vector<std::vector<char>>& grid) {
    if (grid.empty()) {
        return 0;
    }
    int count = 0;
    for (int r = 0; r < static_cast<int>(grid.size()); ++r) {
        for (int c = 0; c < static_cast<int>(grid[0].size()); ++c) {
            if (grid[r][c] == '1') {
                ++count;
                dfs(grid, r, c); // flood whole island
            }
        }
    }
    return count;
}

int main() {
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    std::cout << numIslands(grid) << " (expected 3)\n";
    return 0;
}
