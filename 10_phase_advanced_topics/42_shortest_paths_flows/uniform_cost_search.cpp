// Uniform Cost Search — Dijkstra-style SSSP via priority queue
// Expands the cheapest path cost first (AI / search framing of Dijkstra).
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<int> uniformCostSearch(int V, const std::vector<std::vector<std::pair<int, int>>>& adj,
                                   int S) {
    std::vector<int> dist(V, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        if (cost > dist[u]) continue;
        for (const auto& [v, w] : adj[u]) {
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
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 3});
    adj[2].push_back({3, 1});
    adj[3].push_back({4, 2});

    auto d = uniformCostSearch(V, adj, 0);
    for (int i = 0; i < V; ++i) {
        std::cout << "0->" << i << ": " << d[i] << "\n";
    }
    // expected: 0,2,3,4,6
    return 0;
}
