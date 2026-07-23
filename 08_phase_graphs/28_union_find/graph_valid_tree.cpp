// Graph Valid Tree — https://leetcode.com/problems/graph-valid-tree/
// True iff n nodes + edges form a tree (connected, no cycle).
#include <iostream>
#include <utility>
#include <vector>

struct DSU {
    std::vector<int> parent;
    std::vector<int> rank;
    int comps;

    explicit DSU(int n)
        : parent(static_cast<size_t>(n)), rank(static_cast<size_t>(n), 0), comps(n) {
        for (int i = 0; i < n; ++i) {
            parent[static_cast<size_t>(i)] = i;
        }
    }

    int find(int x) {
        if (parent[static_cast<size_t>(x)] != x) {
            parent[static_cast<size_t>(x)] = find(parent[static_cast<size_t>(x)]);
        }
        return parent[static_cast<size_t>(x)];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false; // redundant edge → cycle
        }
        if (rank[static_cast<size_t>(a)] < rank[static_cast<size_t>(b)]) {
            std::swap(a, b);
        }
        parent[static_cast<size_t>(b)] = a;
        if (rank[static_cast<size_t>(a)] == rank[static_cast<size_t>(b)]) {
            ++rank[static_cast<size_t>(a)];
        }
        --comps;
        return true;
    }
};

bool validTree(int n, const std::vector<std::vector<int>>& edges) {
    if (static_cast<int>(edges.size()) != n - 1) {
        return false; // tree needs exactly n-1 edges
    }
    DSU dsu(n);
    for (const auto& e : edges) {
        if (!dsu.unite(e[0], e[1])) {
            return false;
        }
    }
    return dsu.comps == 1;
}

int main() {
    std::cout << std::boolalpha
              << validTree(5, {{0, 1}, {0, 2}, {0, 3}, {1, 4}}) << " (expected true)\n"
              << validTree(5, {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}})
              << " (expected false)\n";
    return 0;
}
