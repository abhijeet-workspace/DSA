// Bellman-Ford — classic single-source shortest paths; detects negative cycles.
// Related: https://leetcode.com/problems/network-delay-time/ and cheapest flights.
#include <iostream>
#include <vector>

struct Edge {
    int u, v, w;
};

// returns false if negative cycle reachable from src
bool bellmanFord(int n, const std::vector<Edge>& edges, int src, std::vector<int>& dist) {
    const int INF = 1e9;
    dist.assign(static_cast<size_t>(n), INF);
    dist[static_cast<size_t>(src)] = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool changed = false;
        for (const auto& e : edges) {
            if (dist[static_cast<size_t>(e.u)] == INF)
                continue;
            if (dist[static_cast<size_t>(e.v)] > dist[static_cast<size_t>(e.u)] + e.w) {
                dist[static_cast<size_t>(e.v)] = dist[static_cast<size_t>(e.u)] + e.w;
                changed = true;
            }
        }
        if (!changed)
            break;
    }
    for (const auto& e : edges) {
        if (dist[static_cast<size_t>(e.u)] == INF)
            continue;
        if (dist[static_cast<size_t>(e.v)] > dist[static_cast<size_t>(e.u)] + e.w)
            return false;
    }
    return true;
}

int main() {
    std::vector<int> dist;
    bool ok = bellmanFord(5,
                          {{0, 1, 6},
                           {0, 2, 7},
                           {1, 2, 8},
                           {1, 3, 5},
                           {1, 4, -4},
                           {2, 3, -3},
                           {2, 4, 9},
                           {3, 1, -2},
                           {4, 3, 7},
                           {4, 0, 2}},
                          0, dist);
    std::cout << std::boolalpha << ok << " dist[3]=" << dist[3] << " (expected true / 2)\n";
    return 0;
}
