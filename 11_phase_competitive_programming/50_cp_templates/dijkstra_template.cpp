// Dijkstra template — non-negative weighted shortest paths
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<long long> dijkstra(int n, int src,
                                const std::vector<std::vector<std::pair<int, int>>>& g) {
    const long long INF = (1LL << 60);
    std::vector<long long> dist(n, INF);
    using Node = std::pair<long long, int>;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    // 0--1-->1--2-->2, 0--4-->2
    std::vector<std::vector<std::pair<int, int>>> g(3);
    g[0].push_back({1, 1});
    g[1].push_back({2, 2});
    g[0].push_back({2, 4});
    auto dist = dijkstra(3, 0, g);
    std::cout << "dist2=" << dist[2] << " expected=3\n";
    const bool ok = (dist[2] == 3);
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
