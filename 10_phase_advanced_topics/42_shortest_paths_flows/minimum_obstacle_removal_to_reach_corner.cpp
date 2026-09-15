// Minimum Obstacle Removal to Reach Corner — LeetCode 2290
// 0-1 BFS: empty cell cost 0, obstacle cost 1 to remove.
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

int minimumObstacles(std::vector<std::vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    std::vector<std::vector<int>> dist(static_cast<size_t>(m),
                                       std::vector<int>(static_cast<size_t>(n), 1e9));
    std::deque<std::pair<int, int>> dq;
    dist[0][0] = grid[0][0]; // 0 or 1
    dq.push_front({0, 0});
    const int dr[4] = {1, -1, 0, 0};
    const int dc[4] = {0, 0, 1, -1};
    while (!dq.empty()) {
        const auto [r, c] = dq.front();
        dq.pop_front();
        for (int k = 0; k < 4; ++k) {
            const int nr = r + dr[k];
            const int nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                continue;
            }
            const int cost = grid[static_cast<size_t>(nr)][static_cast<size_t>(nc)];
            const int nd = dist[static_cast<size_t>(r)][static_cast<size_t>(c)] + cost;
            if (nd < dist[static_cast<size_t>(nr)][static_cast<size_t>(nc)]) {
                dist[static_cast<size_t>(nr)][static_cast<size_t>(nc)] = nd;
                if (cost == 0) {
                    dq.push_front({nr, nc});
                } else {
                    dq.push_back({nr, nc});
                }
            }
        }
    }
    return dist[static_cast<size_t>(m - 1)][static_cast<size_t>(n - 1)];
}

int main() {
    std::vector<std::vector<int>> g1 = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}};
    std::vector<std::vector<int>> g2 = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
    std::cout << minimumObstacles(g1) << " (expected 2)\n";
    std::cout << minimumObstacles(g2) << " (expected 0)\n";
    return 0;
}
