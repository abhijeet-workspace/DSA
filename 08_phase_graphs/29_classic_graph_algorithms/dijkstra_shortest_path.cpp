// Dijkstra Shortest Path — classic single-source shortest paths (non-negative weights).
// Teaching companion; see also https://leetcode.com/problems/network-delay-time/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<int> dijkstra(int n, const std::vector<std::vector<int>>& edges, int src) {
    std::vector<std::vector<std::pair<int, int>>> g(static_cast<size_t>(n));
    for (const auto& e : edges) g[static_cast<size_t>(e[0])].push_back({e[1], e[2]});
    const int INF = 1e9;
    std::vector<int> dist(static_cast<size_t>(n), INF);
    using P = std::pair<int, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    dist[static_cast<size_t>(src)] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[static_cast<size_t>(u)]) continue;
        for (auto [v, w] : g[static_cast<size_t>(u)]) {
            if (dist[static_cast<size_t>(v)] > d + w) {
                dist[static_cast<size_t>(v)] = d + w;
                pq.push({dist[static_cast<size_t>(v)], v});
            }
        }
    }
    return dist;
}

int main() {
    const auto d = dijkstra(5, {{0, 1, 10}, {0, 2, 3}, {2, 1, 1}, {1, 3, 2}, {2, 3, 8}, {2, 4, 2}, {3, 4, 7}}, 0);
    std::cout << d[3] << " (expected 6)\n";
    std::cout << d[4] << " (expected 5)\n";
    return 0;
}
