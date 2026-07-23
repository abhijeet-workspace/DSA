// Dijkstra — non-negative weighted SSSP via min-heap
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<int> dijkstra(int V, const std::vector<std::vector<std::pair<int, int>>>& adj,
                          int S) {
    std::vector<int> dist(V, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) {
            continue; // stale heap entry
        }
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;
    std::vector<std::vector<std::pair<int, int>>> adj(V);
    adj[0].push_back({1, 9});
    adj[0].push_back({2, 6});
    adj[0].push_back({3, 5});
    adj[0].push_back({4, 3});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 4});
    std::vector<int> d = dijkstra(V, adj, 0);
    for (int i = 0; i < V; ++i) {
        std::cout << "0->" << i << ": " << d[i] << "\n";
    }
    // expected: 0,8,6,5,3
    return 0;
}
