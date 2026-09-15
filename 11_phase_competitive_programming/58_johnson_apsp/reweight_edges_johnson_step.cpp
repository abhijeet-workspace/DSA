// Reweight Edges — Johnson step teaching
// Given potentials h[], w'(u,v)=w+h[u]-h[v] >= 0 if h from BF.
#include <iostream>
#include <vector>

struct Edge {
    int u, v;
    long long w;
};

std::vector<long long> potentials(int n, std::vector<Edge> edges) {
    // super-source  n  connected to all with 0
    for (int i = 0; i < n; ++i)
        edges.push_back({n, i, 0});
    std::vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; ++i)
        for (const auto& e : edges)
            if (h[e.u] + e.w < h[e.v])
                h[e.v] = h[e.u] + e.w;
    return std::vector<long long>(h.begin(), h.begin() + n);
}

int main() {
    std::vector<Edge> edges = {{0, 1, 1}, {1, 2, -2}, {0, 2, 3}};
    auto h = potentials(3, edges);
    auto rew = [&](int u, int v, long long w) { return w + h[u] - h[v]; };
    std::cout << rew(0, 1, 1) << " " << rew(1, 2, -2) << " " << rew(0, 2, 3) << "\n";
    bool ok = rew(0, 1, 1) >= 0 && rew(1, 2, -2) >= 0 && rew(0, 2, 3) >= 0;
    std::cout << (ok ? "nonneg" : "fail") << " (expected nonneg)\n";
    return 0;
}
