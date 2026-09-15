// Minimum Path Sum — https://leetcode.com/problems/minimum-path-sum/
#include <algorithm>
#include <iostream>
#include <vector>

int minPathSum(std::vector<std::vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    for (int j = 1; j < n; ++j)
        grid[0][static_cast<size_t>(j)] += grid[0][static_cast<size_t>(j - 1)];
    for (int i = 1; i < m; ++i)
        grid[static_cast<size_t>(i)][0] += grid[static_cast<size_t>(i - 1)][0];
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            grid[static_cast<size_t>(i)][static_cast<size_t>(j)] +=
                std::min(grid[static_cast<size_t>(i - 1)][static_cast<size_t>(j)],
                         grid[static_cast<size_t>(i)][static_cast<size_t>(j - 1)]);
        }
    }
    return grid[static_cast<size_t>(m - 1)][static_cast<size_t>(n - 1)];
}

int main() {
    std::vector<std::vector<int>> g{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    std::cout << minPathSum(g) << " (expected 7)\n";
    return 0;
}
