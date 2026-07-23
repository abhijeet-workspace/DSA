// Negative cycle detection — Bellman-Ford Vth relaxation.
// True if a negative cycle is reachable from src.
#include <iostream>
#include <vector>

struct Edge {
    int src;
    int dest;
    int weight;
};

bool isNegativeCyclePresent(int V, const std::vector<Edge>& edges, int src) {
    std::vector<int> dist(static_cast<size_t>(V), 1000000000);
    dist[static_cast<size_t>(src)] = 0;
    for (int i = 1; i <= V - 1; ++i) {
        for (const Edge& e : edges) {
            if (dist[static_cast<size_t>(e.src)] != 1000000000 &&
                dist[static_cast<size_t>(e.src)] + e.weight <
                    dist[static_cast<size_t>(e.dest)]) {
                dist[static_cast<size_t>(e.dest)] =
                    dist[static_cast<size_t>(e.src)] + e.weight;
            }
        }
    }
    for (const Edge& e : edges) {
        if (dist[static_cast<size_t>(e.src)] != 1000000000 &&
            dist[static_cast<size_t>(e.src)] + e.weight <
                dist[static_cast<size_t>(e.dest)]) {
            return true; // still relaxing → negative cycle
        }
    }
    return false;
}

int main() {
    const int V = 4;
    const std::vector<Edge> edges = {
        {0, 1, 1},
        {1, 2, -1},
        {2, 3, -1},
        {3, 1, -1}, // cycle 1→2→3→1 weight -3
    };
    std::cout << (isNegativeCyclePresent(V, edges, 0) ? "YES" : "NO")
              << " (expected YES)\n";
    return 0;
}
