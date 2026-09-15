// Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
// https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

struct DSU {
    std::vector<int> p, r;
    explicit DSU(int n) : p(static_cast<size_t>(n)), r(static_cast<size_t>(n), 0) {
        std::iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[static_cast<size_t>(x)] == x
                   ? x
                   : p[static_cast<size_t>(x)] = find(p[static_cast<size_t>(x)]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[static_cast<size_t>(a)] < r[static_cast<size_t>(b)])
            std::swap(a, b);
        p[static_cast<size_t>(b)] = a;
        if (r[static_cast<size_t>(a)] == r[static_cast<size_t>(b)])
            ++r[static_cast<size_t>(a)];
        return true;
    }
};

int mstWeight(int n, const std::vector<std::vector<int>>& edges, int forceIn, int forceOut) {
    DSU dsu(n);
    int w = 0, used = 0;
    if (forceIn != -1) {
        const auto& e = edges[static_cast<size_t>(forceIn)];
        dsu.unite(e[0], e[1]);
        w += e[2];
        ++used;
    }
    for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
        if (i == forceOut || i == forceIn)
            continue;
        const auto& e = edges[static_cast<size_t>(i)];
        if (dsu.unite(e[0], e[1])) {
            w += e[2];
            ++used;
        }
    }
    return used == n - 1 ? w : 1e9;
}

std::vector<std::vector<int>>
findCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>> edges) {
    const int m = static_cast<int>(edges.size());
    for (int i = 0; i < m; ++i)
        edges[static_cast<size_t>(i)].push_back(i); // original index
    std::sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) { return a[2] < b[2]; });
    int base = mstWeight(n, edges, -1, -1);
    std::vector<int> critical, pseudo;
    for (int i = 0; i < m; ++i) {
        if (mstWeight(n, edges, -1, i) > base)
            critical.push_back(edges[static_cast<size_t>(i)][3]);
        else if (mstWeight(n, edges, i, -1) == base)
            pseudo.push_back(edges[static_cast<size_t>(i)][3]);
    }
    return {critical, pseudo};
}

int main() {
    auto r = findCriticalAndPseudoCriticalEdges(
        5, {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}});
    std::cout << "critical=" << r[0].size() << " pseudo=" << r[1].size() << "\n";
    return 0;
}
