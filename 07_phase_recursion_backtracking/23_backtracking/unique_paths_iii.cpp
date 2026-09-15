// Unique Paths III — https://leetcode.com/problems/unique-paths-iii/
// Count paths from start to end that walk every empty square exactly once.
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& grid, int r, int c, int remain, int& ways) {
    const int R = static_cast<int>(grid.size());
    const int C = static_cast<int>(grid[0].size());
    if (r < 0 || c < 0 || r >= R || c >= C || grid[static_cast<size_t>(r)][static_cast<size_t>(c)] == -1)
        return;
    if (grid[static_cast<size_t>(r)][static_cast<size_t>(c)] == 2) {
        if (remain == 0) ++ways;
        return;
    }
    const int old = grid[static_cast<size_t>(r)][static_cast<size_t>(c)];
    grid[static_cast<size_t>(r)][static_cast<size_t>(c)] = -1;
    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};
    for (int k = 0; k < 4; ++k) dfs(grid, r + dr[k], c + dc[k], remain - 1, ways);
    grid[static_cast<size_t>(r)][static_cast<size_t>(c)] = old;
}

int uniquePathsIII(std::vector<std::vector<int>> grid) {
    int sr = 0, sc = 0, empty = 0;
    for (int i = 0; i < static_cast<int>(grid.size()); ++i) {
        for (int j = 0; j < static_cast<int>(grid[0].size()); ++j) {
            if (grid[static_cast<size_t>(i)][static_cast<size_t>(j)] == 1) {
                sr = i;
                sc = j;
            }
            if (grid[static_cast<size_t>(i)][static_cast<size_t>(j)] != -1) ++empty;
        }
    }
    // remain steps after leaving start: empty-1 (include end cell in count)
    int ways = 0;
    dfs(grid, sr, sc, empty - 1, ways);
    return ways;
}

int main() {
    std::vector<std::vector<int>> g = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    std::cout << uniquePathsIII(g) << " (expected 2)\n";
    return 0;
}
