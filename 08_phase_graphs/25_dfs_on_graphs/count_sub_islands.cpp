// Count Sub Islands — https://leetcode.com/problems/count-sub-islands/
// Count islands in grid2 whose all land cells are land in grid1.
#include <iostream>
#include <vector>

bool dfs(const std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2, int r, int c) {
    const int R = static_cast<int>(grid2.size());
    const int C = static_cast<int>(grid2[0].size());
    if (r < 0 || c < 0 || r >= R || c >= C || grid2[static_cast<size_t>(r)][static_cast<size_t>(c)] == 0)
        return true;
    grid2[static_cast<size_t>(r)][static_cast<size_t>(c)] = 0;
    bool ok = grid1[static_cast<size_t>(r)][static_cast<size_t>(c)] == 1;
    ok &= dfs(grid1, grid2, r + 1, c);
    ok &= dfs(grid1, grid2, r - 1, c);
    ok &= dfs(grid1, grid2, r, c + 1);
    ok &= dfs(grid1, grid2, r, c - 1);
    return ok;
}

int countSubIslands(const std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>> grid2) {
    int count = 0;
    for (int i = 0; i < static_cast<int>(grid2.size()); ++i) {
        for (int j = 0; j < static_cast<int>(grid2[0].size()); ++j) {
            if (grid2[static_cast<size_t>(i)][static_cast<size_t>(j)] == 1) {
                if (dfs(grid1, grid2, i, j)) ++count;
            }
        }
    }
    return count;
}

int main() {
    std::vector<std::vector<int>> g1 = {{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0},
                                        {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}};
    std::vector<std::vector<int>> g2 = {{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0},
                                        {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};
    std::cout << countSubIslands(g1, g2) << " (expected 3)\n";
    return 0;
}
