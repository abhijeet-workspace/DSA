// Network Delay Time — LeetCode 743
// SSSP Dijkstra (pedagogy: building block for Johnson's V Dijkstras).
#include <iostream>
#include <queue>
#include <vector>

int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (const auto& t : times)
        g[t[0]].push_back({t[1], t[2]});
    const int INF = 1e9;
    std::vector<int> dist(n + 1, INF);
    using P = std::pair<int, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    dist[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto [v, w] : g[u])
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] >= INF)
            return -1;
        ans = std::max(ans, dist[i]);
    }
    return ans;
}

int main() {
    std::cout << networkDelayTime({{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2) << " (expected 2)\n";
    return 0;
}
