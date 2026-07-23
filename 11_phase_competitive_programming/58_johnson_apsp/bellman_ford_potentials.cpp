// Bellman–Ford Potentials — teaching piece for Johnson / difference constraints
// Compute h[] so reweighted edges w+h[u]-h[v] are non-negative (or detect neg cycle).
#include <iostream>
#include <limits>
#include <vector>

struct Edge {
    int u, v;
    long long w;
};

bool computePotentials(int n, const std::vector<Edge>& edges,
                       std::vector<long long>& h) {
    const long long INF = std::numeric_limits<long long>::max() / 4;
    std::vector<Edge> all = edges;
    int s = n; // super-source
    for (int v = 0; v < n; ++v) all.push_back({s, v, 0});

    h.assign(static_cast<size_t>(n) + 1, INF);
    h[static_cast<size_t>(s)] = 0;
    for (int i = 0; i < n; ++i) {
        bool upd = false;
        for (const Edge& e : all) {
            if (h[static_cast<size_t>(e.u)] == INF) continue;
            if (h[static_cast<size_t>(e.u)] + e.w < h[static_cast<size_t>(e.v)]) {
                h[static_cast<size_t>(e.v)] = h[static_cast<size_t>(e.u)] + e.w;
                upd = true;
            }
        }
        if (!upd) break;
    }
    for (const Edge& e : all) {
        if (h[static_cast<size_t>(e.u)] != INF
            && h[static_cast<size_t>(e.u)] + e.w < h[static_cast<size_t>(e.v)]) {
            return false; // negative cycle
        }
    }
    h.resize(static_cast<size_t>(n)); // drop super-source
    return true;
}

int main() {
    std::vector<Edge> edges = {{0, 1, 1}, {1, 2, -1}, {0, 2, 3}};
    std::vector<long long> h;
    bool ok = computePotentials(3, edges, h);
    std::cout << "ok=" << (ok ? 1 : 0) << " (expected 1)\n";
    std::cout << "h=";
    for (size_t i = 0; i < h.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << h[i];
    }
    std::cout << "\n";
    bool allNonNeg = true;
    for (const Edge& e : edges) {
        long long nw = e.w + h[static_cast<size_t>(e.u)] - h[static_cast<size_t>(e.v)];
        if (nw < 0) allNonNeg = false;
        std::cout << "w'(" << e.u << "," << e.v << ")=" << nw << "\n";
    }
    std::cout << "all_nonneg=" << (allNonNeg ? 1 : 0) << " (expected 1)\n";
    return 0;
}
