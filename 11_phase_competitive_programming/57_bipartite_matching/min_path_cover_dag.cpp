// Minimum Path Cover in DAG — via bipartite matching
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

int minPathCover(int n, const std::vector<std::pair<int, int>>& edges) {
    g.assign(static_cast<size_t>(n) + 1, {});
    for (auto [u, v] : edges)
        g[static_cast<size_t>(u)].push_back(v);
    mt.assign(static_cast<size_t>(n) + 1, -1);
    vis.assign(static_cast<size_t>(n) + 1, 0);
    int match = 0;
    for (int v = 1; v <= n; ++v) {
        ++timer;
        if (tryKuhn(v))
            ++match;
    }
    return n - match;
}

int main() {
    std::cout << minPathCover(4, {{1, 2}, {2, 3}, {1, 3}, {3, 4}}) << " (expected 1)\n";
    return 0;
}
