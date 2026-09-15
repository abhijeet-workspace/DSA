// Shortest Bridge — https://leetcode.com/problems/shortest-bridge/
// Flip minimum 0s to connect two islands (4-dir).
#include <iostream>
#include <queue>
#include <vector>

void dfs(std::vector<std::vector<int>>& grid, int r, int c, std::queue<std::pair<int, int>>& q) {
    const int n = static_cast<int>(grid.size());
    if (r < 0 || c < 0 || r >= n || c >= n ||
        grid[static_cast<size_t>(r)][static_cast<size_t>(c)] != 1)
        return;
    grid[static_cast<size_t>(r)][static_cast<size_t>(c)] = 2;
    q.push({r, c});
    dfs(grid, r + 1, c, q);
    dfs(grid, r - 1, c, q);
    dfs(grid, r, c + 1, q);
    dfs(grid, r, c - 1, q);
}

int shortestBridge(std::vector<std::vector<int>> grid) {
    const int n = static_cast<int>(grid.size());
    std::queue<std::pair<int, int>> q;
    bool found = false;
    for (int i = 0; i < n && !found; ++i)
        for (int j = 0; j < n && !found; ++j)
            if (grid[static_cast<size_t>(i)][static_cast<size_t>(j)] == 1) {
                dfs(grid, i, j, q);
                found = true;
            }
    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};
    int dist = 0;
    while (!q.empty()) {
        int sz = static_cast<int>(q.size());
        while (sz--) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;
                if (grid[static_cast<size_t>(nr)][static_cast<size_t>(nc)] == 1)
                    return dist;
                if (grid[static_cast<size_t>(nr)][static_cast<size_t>(nc)] == 0) {
                    grid[static_cast<size_t>(nr)][static_cast<size_t>(nc)] = 2;
                    q.push({nr, nc});
                }
            }
        }
        ++dist;
    }
    return -1;
}

int main() {
    std::cout << shortestBridge({{0, 1}, {1, 0}}) << " (expected 1)\n";
    std::cout << shortestBridge({{0, 1, 0}, {0, 0, 0}, {0, 0, 1}}) << " (expected 2)\n";
    return 0;
}
