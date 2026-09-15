// Minimum Cost to Make at Least One Valid Path — LeetCode 1368
// 0-1 BFS: follow cell arrow cost 0; change direction cost 1.
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

int minCost(std::vector<std::vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    const int dr[4] = {0, 0, 1, -1};
    const int dc[4] = {1, -1, 0, 0};
    // signs match grid values 1..4 (right,left,down,up) at index dir-1
    std::vector<std::vector<int>> dist(static_cast<size_t>(m),
                                       std::vector<int>(static_cast<size_t>(n), 1e9));
    std::deque<std::pair<int, int>> dq;
    dist[0][0] = 0;
    dq.push_front({0, 0});
    while (!dq.empty()) {
        const auto [r, c] = dq.front();
        dq.pop_front();
        for (int k = 0; k < 4; ++k) {
            const int nr = r + dr[k];
            const int nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                continue;
            }
            const int cost = (k + 1 == grid[static_cast<size_t>(r)][static_cast<size_t>(c)]) ? 0 : 1;
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
    std::vector<std::vector<int>> grid = {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
    std::cout << minCost(grid) << " (expected 3)\n";
    return 0;
}
