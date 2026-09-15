// Detect Negative Cycle — Bellman–Ford
#include <iostream>
#include <vector>

struct Edge {
    int u, v;
    long long w;
};

bool hasNegativeCycle(int n, const std::vector<Edge>& edges) {
    std::vector<long long> dist(n, 0); // 0-init finds cycle anywhere
    for (int i = 0; i < n - 1; ++i)
        for (const auto& e : edges)
            if (dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
    for (const auto& e : edges)
        if (dist[e.u] + e.w < dist[e.v])
            return true;
    return false;
}

int main() {
    std::cout << hasNegativeCycle(3, {{0, 1, 1}, {1, 2, -1}, {2, 0, -1}}) << " (expected 1)\n";
    std::cout << hasNegativeCycle(3, {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}}) << " (expected 0)\n";
    return 0;
}
