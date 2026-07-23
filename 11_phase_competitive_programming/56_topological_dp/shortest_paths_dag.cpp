// Shortest Paths on DAG — CP classic
// Single-source shortest paths on a weighted DAG in O(V+E) (handles negatives).
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

struct Edge {
    int to;
    long long w;
};

std::vector<long long> shortestPathsDAG(
    int n, const std::vector<std::vector<Edge>>& g, int src) {
    const long long INF = std::numeric_limits<long long>::max() / 4;
    std::vector<int> indeg(static_cast<size_t>(n) + 1, 0);
    for (int u = 1; u <= n; ++u)
        for (const Edge& e : g[static_cast<size_t>(u)]) ++indeg[static_cast<size_t>(e.to)];

    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indeg[static_cast<size_t>(i)] == 0) q.push(i);
    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (const Edge& e : g[static_cast<size_t>(u)])
            if (--indeg[static_cast<size_t>(e.to)] == 0) q.push(e.to);
    }

    std::vector<long long> dist(static_cast<size_t>(n) + 1, INF);
    dist[static_cast<size_t>(src)] = 0;
    for (int u : order) {
        if (dist[static_cast<size_t>(u)] >= INF / 2) continue;
        for (const Edge& e : g[static_cast<size_t>(u)]) {
            long long nd = dist[static_cast<size_t>(u)] + e.w;
            if (nd < dist[static_cast<size_t>(e.to)]) dist[static_cast<size_t>(e.to)] = nd;
        }
    }
    return dist;
}

int main() {
    std::vector<std::vector<Edge>> g(4);
    g[1].push_back({2, 3});
    g[1].push_back({3, 1});
    g[3].push_back({2, 1});
    auto d = shortestPathsDAG(3, g, 1);
    std::cout << "dist[2]=" << d[2] << " (expected 2)\n";
    std::cout << "dist[3]=" << d[3] << " (expected 1)\n";
    return 0;
}
