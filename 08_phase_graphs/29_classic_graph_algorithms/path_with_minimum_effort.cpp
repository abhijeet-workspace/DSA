// Path With Minimum Effort — https://leetcode.com/problems/path-with-minimum-effort/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

int minimumEffortPath(const std::vector<std::vector<int>>& heights) {
    const int R = static_cast<int>(heights.size());
    const int C = static_cast<int>(heights[0].size());
    const int INF = 1e9;
    std::vector<std::vector<int>> dist(static_cast<size_t>(R), std::vector<int>(static_cast<size_t>(C), INF));
    using T = std::tuple<int, int, int>; // effort, r, c
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};
    while (!pq.empty()) {
        auto [eff, r, c] = pq.top();
        pq.pop();
        if (r == R - 1 && c == C - 1) return eff;
        if (eff != dist[static_cast<size_t>(r)][static_cast<size_t>(c)]) continue;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            int next = std::max(eff, std::abs(heights[static_cast<size_t>(nr)][static_cast<size_t>(nc)] -
                                              heights[static_cast<size_t>(r)][static_cast<size_t>(c)]));
            if (next < dist[static_cast<size_t>(nr)][static_cast<size_t>(nc)]) {
                dist[static_cast<size_t>(nr)][static_cast<size_t>(nc)] = next;
                pq.push({next, nr, nc});
            }
        }
    }
    return 0;
}

int main() {
    std::cout << minimumEffortPath({{1, 2, 2}, {3, 8, 2}, {5, 3, 5}}) << " (expected 2)\n";
    return 0;
}
