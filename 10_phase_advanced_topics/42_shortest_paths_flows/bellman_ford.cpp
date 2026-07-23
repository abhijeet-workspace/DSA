// Bellman-Ford — SSSP with negative edges; detect negative cycles
// Relax all edges |V|-1 times, then one more pass for cycle check.
#include <iostream>
#include <vector>

const int INF = 1e9;

struct Edge {
    int src;
    int dest;
    int weight;
};

// Returns empty on negative cycle; otherwise distance vector (INF = unreachable).
std::vector<int> bellmanFord(int vertices, const std::vector<Edge>& edges, int src) {
    std::vector<int> dist(vertices, INF);
    dist[src] = 0;
    for (int i = 1; i <= vertices - 1; ++i) {
        for (const Edge& e : edges) {
            if (dist[e.src] != INF && dist[e.src] + e.weight < dist[e.dest]) {
                dist[e.dest] = dist[e.src] + e.weight;
            }
        }
    }
    for (const Edge& e : edges) {
        if (dist[e.src] != INF && dist[e.src] + e.weight < dist[e.dest]) {
            return {}; // negative cycle reachable from src
        }
    }
    return dist;
}

int main() {
    std::vector<Edge> edges1 = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    auto d1 = bellmanFord(5, edges1, 0);
    std::cout << "dist[4]=" << d1[4] << " (expected -2)\n";

    std::vector<Edge> edges2 = {{0, 1, 4}, {1, 2, 3}, {2, 3, -6}, {3, 1, 1}};
    auto d2 = bellmanFord(4, edges2, 0);
    std::cout << "neg_cycle=" << (d2.empty() ? "yes" : "no") << " (expected yes)\n";
    return 0;
}
