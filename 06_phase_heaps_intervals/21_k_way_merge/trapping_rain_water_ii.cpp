// Trapping Rain Water II — https://leetcode.com/problems/trapping-rain-water-ii/
// Min-heap multi-source BFS from boundary; water level = max(boundary height so far).
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int trapRainWater(std::vector<std::vector<int>>& heightMap) {
    if (heightMap.empty() || heightMap[0].empty()) return 0;
    const int m = static_cast<int>(heightMap.size());
    const int n = static_cast<int>(heightMap[0].size());
    using T = std::tuple<int, int, int>; // height, r, c
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    std::vector<std::vector<char>> vis(static_cast<size_t>(m), std::vector<char>(static_cast<size_t>(n), 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                pq.push({heightMap[static_cast<size_t>(i)][static_cast<size_t>(j)], i, j});
                vis[static_cast<size_t>(i)][static_cast<size_t>(j)] = 1;
            }
        }
    }
    const int dr[4] = {1, -1, 0, 0};
    const int dc[4] = {0, 0, 1, -1};
    int water = 0;
    while (!pq.empty()) {
        auto [h, r, c] = pq.top();
        pq.pop();
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || vis[static_cast<size_t>(nr)][static_cast<size_t>(nc)]) continue;
            vis[static_cast<size_t>(nr)][static_cast<size_t>(nc)] = 1;
            int nh = heightMap[static_cast<size_t>(nr)][static_cast<size_t>(nc)];
            water += std::max(0, h - nh);
            pq.push({std::max(h, nh), nr, nc});
        }
    }
    return water;
}

int main() {
    std::vector<std::vector<int>> h = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    std::cout << trapRainWater(h) << " (expected 4)\n";
    return 0;
}
