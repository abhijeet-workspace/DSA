// Network Delay Time — https://leetcode.com/problems/network-delay-time/
// Dijkstra: min time for signal from k to reach all n nodes, or -1.
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<std::vector<std::pair<int, int>>> g(static_cast<size_t>(n + 1));
    for (const auto& t : times)
        g[static_cast<size_t>(t[0])].push_back({t[1], t[2]});
    const int INF = 1e9;
    std::vector<int> dist(static_cast<size_t>(n + 1), INF);
    using P = std::pair<int, int>; // dist, node
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    dist[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[static_cast<size_t>(u)])
            continue;
        for (auto [v, w] : g[static_cast<size_t>(u)]) {
            if (dist[static_cast<size_t>(v)] > d + w) {
                dist[static_cast<size_t>(v)] = d + w;
                pq.push({dist[static_cast<size_t>(v)], v});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[static_cast<size_t>(i)] == INF)
            return -1;
        ans = std::max(ans, dist[static_cast<size_t>(i)]);
    }
    return ans;
}

int main() {
    std::cout << networkDelayTime({{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2) << " (expected 2)\n";
    return 0;
}
