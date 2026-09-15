// As Far from Land as Possible — https://leetcode.com/problems/as-far-from-land-as-possible/
#include <iostream>
#include <queue>
#include <vector>

int maxDistance(std::vector<std::vector<int>> grid) {
    const int n = static_cast<int>(grid.size());
    std::queue<std::pair<int, int>> q;
    int land = 0, water = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (grid[static_cast<size_t>(i)][static_cast<size_t>(j)] == 1) {
                q.push({i, j});
                ++land;
            } else
                ++water;
        }
    if (land == 0 || water == 0)
        return -1;
    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};
    int dist = -1;
    while (!q.empty()) {
        int sz = static_cast<int>(q.size());
        ++dist;
        while (sz--) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;
                if (grid[static_cast<size_t>(nr)][static_cast<size_t>(nc)] != 0)
                    continue;
                grid[static_cast<size_t>(nr)][static_cast<size_t>(nc)] = 1;
                q.push({nr, nc});
            }
        }
    }
    return dist;
}

int main() {
    std::cout << maxDistance({{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}) << " (expected 2)\n";
    return 0;
}
