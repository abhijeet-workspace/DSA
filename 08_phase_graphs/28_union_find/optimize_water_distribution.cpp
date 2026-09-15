// Optimize Water Distribution in a Village — https://leetcode.com/problems/optimize-water-distribution-in-a-village/
// Min cost to supply water: dig wells and/or lay pipes. MST with virtual node 0 for wells.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class DSU {
    std::vector<int> p_, r_;

public:
    explicit DSU(int n) : p_(static_cast<size_t>(n)), r_(static_cast<size_t>(n), 0) {
        std::iota(p_.begin(), p_.end(), 0);
    }
    int find(int x) {
        return p_[static_cast<size_t>(x)] == x ? x
                                               : p_[static_cast<size_t>(x)] = find(p_[static_cast<size_t>(x)]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (r_[static_cast<size_t>(a)] < r_[static_cast<size_t>(b)]) {
            std::swap(a, b);
        }
        p_[static_cast<size_t>(b)] = a;
        if (r_[static_cast<size_t>(a)] == r_[static_cast<size_t>(b)]) {
            ++r_[static_cast<size_t>(a)];
        }
        return true;
    }
};

int minCostToSupplyWater(int n, const std::vector<int>& wells,
                         const std::vector<std::vector<int>>& pipes) {
    std::vector<std::vector<int>> edges; // {cost, u, v}
    for (int i = 1; i <= n; ++i) {
        edges.push_back({wells[static_cast<size_t>(i - 1)], 0, i});
    }
    for (const auto& p : pipes) {
        edges.push_back({p[2], p[0], p[1]});
    }
    std::sort(edges.begin(), edges.end());
    DSU dsu(n + 1);
    int cost = 0;
    int used = 0;
    for (const auto& e : edges) {
        if (dsu.unite(e[1], e[2])) {
            cost += e[0];
            if (++used == n) {
                break;
            }
        }
    }
    return cost;
}

int main() {
    std::cout << minCostToSupplyWater(3, {1, 2, 2}, {{1, 2, 1}, {2, 3, 1}}) << " (expected 3)\n";
    std::cout << minCostToSupplyWater(2, {1, 1}, {{1, 2, 1}, {1, 2, 2}}) << " (expected 2)\n";
    return 0;
}
