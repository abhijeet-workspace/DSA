// Swim in Rising Water — LeetCode 778
// Dijkstra on grid; cost = max elevation seen on the path.
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int swimInWater(std::vector<std::vector<int>>& grid) {
    int n = static_cast<int>(grid.size());
    std::vector<std::vector<int>> seen(n, std::vector<int>(n, 0));
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>,
                        std::greater<std::tuple<int, int, int>>>
        pq;
    pq.push({grid[0][0], 0, 0});
    seen[0][0] = 1;
    const int dr[4] = {1, -1, 0, 0};
    const int dc[4] = {0, 0, 1, -1};
    while (!pq.empty()) {
        auto [t, r, c] = pq.top();
        pq.pop();
        if (r == n - 1 && c == n - 1) {
            return t;
        }
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n || seen[nr][nc]) {
                continue;
            }
            seen[nr][nc] = 1;
            pq.push({std::max(t, grid[nr][nc]), nr, nc});
        }
    }
    return -1;
}

int main() {
    std::vector<std::vector<int>> g = {{0, 2}, {1, 3}};
    std::cout << swimInWater(g) << " (expected 3)\n";
    return 0;
}
