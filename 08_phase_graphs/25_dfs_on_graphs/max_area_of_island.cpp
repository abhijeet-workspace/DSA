// Max Area of Island — https://leetcode.com/problems/max-area-of-island/
// Largest 4-connected component of 1s in a grid; return its area.
#include <algorithm>
#include <iostream>
#include <vector>

int area(std::vector<std::vector<int>>& g, int i, int j) {
    if (i < 0 || j < 0 || i >= static_cast<int>(g.size())
        || j >= static_cast<int>(g[0].size()) || g[i][j] == 0) {
        return 0;
    }
    g[i][j] = 0; // sink visited land
    return 1 + area(g, i + 1, j) + area(g, i - 1, j)
             + area(g, i, j + 1) + area(g, i, j - 1);
}

int maxAreaOfIsland(std::vector<std::vector<int>> grid) {
    int best = 0;
    for (int i = 0; i < static_cast<int>(grid.size()); ++i) {
        for (int j = 0; j < static_cast<int>(grid[0].size()); ++j) {
            if (grid[i][j]) {
                best = std::max(best, area(grid, i, j));
            }
        }
    }
    return best;
}

int main() {
    std::vector<std::vector<int>> g = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0},
    };
    std::cout << maxAreaOfIsland(g) << " (expected 4)\n";
    return 0;
}
