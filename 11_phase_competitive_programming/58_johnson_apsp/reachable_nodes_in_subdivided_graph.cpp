// Reachable Nodes In Subdivided Graph — LeetCode 882
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int reachableNodes(const std::vector<std::vector<int>>& edges, int maxMoves, int n) {
    std::vector<std::vector<std::pair<int, int>>> g(n);
    for (const auto& e : edges) {
        g[e[0]].push_back({e[1], e[2]});
        g[e[1]].push_back({e[0], e[2]});
    }
    const int INF = 1e9;
    std::vector<int> dist(n, INF);
    using P = std::pair<int, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto [v, cnt] : g[u]) {
            int nd = d + cnt + 1;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (dist[i] <= maxMoves)
            ++ans;
    for (const auto& e : edges) {
        int u = e[0], v = e[1], cnt = e[2];
        int a = std::max(0, maxMoves - dist[u]);
        int b = std::max(0, maxMoves - dist[v]);
        ans += std::min(cnt, a + b);
    }
    return ans;
}

int main() {
    std::cout << reachableNodes({{0, 1, 10}, {0, 2, 1}, {1, 2, 2}}, 6, 3) << " (expected 13)\n";
    return 0;
}
