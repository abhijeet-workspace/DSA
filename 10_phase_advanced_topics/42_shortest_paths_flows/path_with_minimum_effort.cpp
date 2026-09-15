// Path With Minimum Effort — https://leetcode.com/problems/path-with-minimum-effort/
// Dijkstra: effort = max absolute height diff along the path.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int minimumEffortPath(std::vector<std::vector<int>>& heights) {
    const int m = static_cast<int>(heights.size());
    const int n = static_cast<int>(heights[0].size());
    std::vector<std::vector<int>> dist(static_cast<size_t>(m),
                                       std::vector<int>(static_cast<size_t>(n), 1e9));
    dist[0][0] = 0;
    using State = std::tuple<int, int, int>; // effort, r, c
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
    pq.push({0, 0, 0});
    const int dr[4] = {1, -1, 0, 0};
    const int dc[4] = {0, 0, 1, -1};
    while (!pq.empty()) {
        const auto [eff, r, c] = pq.top();
        pq.pop();
        if (eff > dist[static_cast<size_t>(r)][static_cast<size_t>(c)]) {
            continue;
        }
        if (r == m - 1 && c == n - 1) {
            return eff;
        }
        for (int k = 0; k < 4; ++k) {
            const int nr = r + dr[k];
            const int nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                continue;
            }
            const int step = std::abs(heights[static_cast<size_t>(r)][static_cast<size_t>(c)]
                                      - heights[static_cast<size_t>(nr)][static_cast<size_t>(nc)]);
            const int ne = std::max(eff, step);
            if (ne < dist[static_cast<size_t>(nr)][static_cast<size_t>(nc)]) {
                dist[static_cast<size_t>(nr)][static_cast<size_t>(nc)] = ne;
                pq.push({ne, nr, nc});
            }
        }
    }
    return 0;
}

int main() {
    std::vector<std::vector<int>> h = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    std::cout << minimumEffortPath(h) << " (expected 2)\n";
    return 0;
}
