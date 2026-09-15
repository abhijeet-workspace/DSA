// Shortest Path Visiting All Nodes — https://leetcode.com/problems/shortest-path-visiting-all-nodes/
#include <iostream>
#include <queue>
#include <vector>

int shortestPathLength(std::vector<std::vector<int>>& graph) {
    const int n = static_cast<int>(graph.size());
    const int full = (1 << n) - 1;
    std::queue<std::tuple<int, int, int>> q; // node, mask, dist
    std::vector<std::vector<char>> seen(n, std::vector<char>(1 << n, 0));
    for (int i = 0; i < n; ++i) {
        q.emplace(i, 1 << i, 0);
        seen[static_cast<size_t>(i)][static_cast<size_t>(1 << i)] = 1;
    }
    while (!q.empty()) {
        auto [u, mask, d] = q.front();
        q.pop();
        if (mask == full) return d;
        for (int v : graph[static_cast<size_t>(u)]) {
            const int nmask = mask | (1 << v);
            if (!seen[static_cast<size_t>(v)][static_cast<size_t>(nmask)]) {
                seen[static_cast<size_t>(v)][static_cast<size_t>(nmask)] = 1;
                q.emplace(v, nmask, d + 1);
            }
        }
    }
    return 0;
}

int main() {
    std::vector<std::vector<int>> g{{1, 2, 3}, {0}, {0}, {0}};
    std::cout << shortestPathLength(g) << " (expected 4)\n";
    return 0;
}
