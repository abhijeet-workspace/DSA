// Maximum Independent Set in Bipartite Graph — Konig
// MIS = V - MVC = V - maximum matching.
#include <iostream>
#include <vector>

int timer = 1;
std::vector<std::vector<int>> g;
std::vector<int> mt, vis;
bool tryKuhn(int v) {
    if (vis[static_cast<size_t>(v)] == timer)
        return false;
    vis[static_cast<size_t>(v)] = timer;
    for (int to : g[static_cast<size_t>(v)]) {
        if (mt[static_cast<size_t>(to)] == -1 || tryKuhn(mt[static_cast<size_t>(to)])) {
            mt[static_cast<size_t>(to)] = v;
            return true;
        }
    }
    return false;
}

int maxIndependentSetBipartite(int nL, int nR, const std::vector<std::pair<int, int>>& edges) {
    g.assign(static_cast<size_t>(nL) + 1, {});
    for (auto [u, v] : edges)
        g[static_cast<size_t>(u)].push_back(v);
    mt.assign(static_cast<size_t>(nR) + 1, -1);
    vis.assign(static_cast<size_t>(nL) + 1, 0);
    int match = 0;
    for (int v = 1; v <= nL; ++v) {
        ++timer;
        if (tryKuhn(v))
            ++match;
    }
    return nL + nR - match; // |V| - MVC, MVC=matching
}

int main() {
    // path L1-R1-L2 : matching 1, MIS 2
    std::cout << maxIndependentSetBipartite(2, 1, {{1, 1}, {2, 1}}) << " (expected 2)\n";
    return 0;
}
