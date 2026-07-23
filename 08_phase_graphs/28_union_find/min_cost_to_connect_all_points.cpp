// Min Cost to Connect All Points — https://leetcode.com/problems/min-cost-to-connect-all-points/
// Kruskal MST on complete graph with Manhattan distances.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

struct DSU {
    std::vector<int> p;
    std::vector<int> r;
    explicit DSU(int n) : p(static_cast<size_t>(n)), r(static_cast<size_t>(n), 0) {
        for (int i = 0; i < n; ++i) {
            p[static_cast<size_t>(i)] = i;
        }
    }
    int find(int x) {
        return p[static_cast<size_t>(x)] == x
                   ? x
                   : p[static_cast<size_t>(x)] = find(p[static_cast<size_t>(x)]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (r[static_cast<size_t>(a)] < r[static_cast<size_t>(b)]) {
            std::swap(a, b);
        }
        p[static_cast<size_t>(b)] = a;
        if (r[static_cast<size_t>(a)] == r[static_cast<size_t>(b)]) {
            ++r[static_cast<size_t>(a)];
        }
        return true;
    }
};

int minCostConnectPoints(std::vector<std::vector<int>>& points) {
    const int n = static_cast<int>(points.size());
    std::vector<std::tuple<int, int, int>> edges; // w, i, j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            const int w = std::abs(points[static_cast<size_t>(i)][0] -
                                   points[static_cast<size_t>(j)][0]) +
                          std::abs(points[static_cast<size_t>(i)][1] -
                                   points[static_cast<size_t>(j)][1]);
            edges.emplace_back(w, i, j);
        }
    }
    std::sort(edges.begin(), edges.end());
    DSU dsu(n);
    int cost = 0;
    int used = 0;
    for (const auto& [w, a, b] : edges) {
        if (dsu.unite(a, b)) {
            cost += w;
            if (++used == n - 1) {
                break;
            }
        }
    }
    return cost;
}

int main() {
    std::vector<std::vector<int>> p = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    std::cout << minCostConnectPoints(p) << " (expected 20)\n";
    return 0;
}
