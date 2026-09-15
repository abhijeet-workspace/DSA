// Dijkstra on Reweighted Edges — Johnson inner loop teaching
#include <iostream>
#include <queue>
#include <vector>

std::vector<long long> dijkstra(int n, int src,
                                const std::vector<std::vector<std::pair<int, long long>>>& g) {
    const long long INF = 4e18;
    std::vector<long long> dist(n, INF);
    using P = std::pair<long long, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    dist[src] = 0;
    pq.push({0, src});
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
    return dist;
}

int main() {
    // Already-nonnegative reweighted graph
    std::vector<std::vector<std::pair<int, long long>>> g(3);
    g[0] = {{1, 2}, {2, 5}};
    g[1] = {{2, 1}};
    auto d = dijkstra(3, 0, g);
    std::cout << d[2] << " (expected 3)\n";
    return 0;
}
