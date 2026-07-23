// Rotting Oranges — https://leetcode.com/problems/rotting-oranges/
// Minutes until all fresh oranges rot; multi-source BFS from initial rotten.
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int orangesRotting(std::vector<std::vector<int>>& grid) {
    if (grid.empty()) {
        return 0;
    }
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    std::queue<std::pair<int, int>> q;
    int fresh = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                ++fresh;
            }
        }
    }
    if (fresh == 0) {
        return 0;
    }

    int minutes = 0;
    const int dirs[] = {0, 1, 0, -1, 0};
    while (!q.empty() && fresh > 0) {
        const int level = static_cast<int>(q.size());
        ++minutes; // one minute per BFS layer
        for (int i = 0; i < level; ++i) {
            auto [r, c] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                const int nr = r + dirs[d];
                const int nc = c + dirs[d + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    --fresh;
                    q.push({nr, nc});
                }
            }
        }
    }
    return fresh == 0 ? minutes : -1;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1},
    };
    std::cout << orangesRotting(grid) << " (expected 4)\n";
    return 0;
}
