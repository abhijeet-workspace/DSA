// Swim in Rising Water — https://leetcode.com/problems/swim-in-rising-water/
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int swimInWater(const std::vector<std::vector<int>>& grid) {
    const int n = static_cast<int>(grid.size());
    std::vector<std::vector<char>> vis(static_cast<size_t>(n),
                                       std::vector<char>(static_cast<size_t>(n), 0));
    using T = std::tuple<int, int, int>; // height, r, c
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    pq.push({grid[0][0], 0, 0});
    vis[0][0] = 1;
    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};
    int ans = 0;
    while (!pq.empty()) {
        auto [h, r, c] = pq.top();
        pq.pop();
        ans = std::max(ans, h);
        if (r == n - 1 && c == n - 1)
            return ans;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n ||
                vis[static_cast<size_t>(nr)][static_cast<size_t>(nc)])
                continue;
            vis[static_cast<size_t>(nr)][static_cast<size_t>(nc)] = 1;
            pq.push({grid[static_cast<size_t>(nr)][static_cast<size_t>(nc)], nr, nc});
        }
    }
    return ans;
}

int main() {
    std::cout << swimInWater({{0, 2}, {1, 3}}) << " (expected 3)\n";
    return 0;
}
