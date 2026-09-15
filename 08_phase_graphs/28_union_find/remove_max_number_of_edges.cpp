// Remove Max Number of Edges to Keep Graph Fully Traversable — LeetCode 1579
// Dual DSU for Alice/Bob; prefer type-3 edges, then type-1/2; count removable.
#include <iostream>
#include <numeric>
#include <vector>

struct DSU {
    std::vector<int> parent;
    std::vector<int> rank;
    int components;
    explicit DSU(int n)
        : parent(static_cast<size_t>(n + 1)),
          rank(static_cast<size_t>(n + 1), 1),
          components(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[static_cast<size_t>(i)] == i) {
            return i;
        }
        return parent[static_cast<size_t>(i)] = find(parent[static_cast<size_t>(i)]);
    }
    bool unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri == rj) {
            return false;
        }
        if (rank[static_cast<size_t>(ri)] < rank[static_cast<size_t>(rj)]) {
            parent[static_cast<size_t>(ri)] = rj;
        } else if (rank[static_cast<size_t>(ri)] > rank[static_cast<size_t>(rj)]) {
            parent[static_cast<size_t>(rj)] = ri;
        } else {
            parent[static_cast<size_t>(rj)] = ri;
            ++rank[static_cast<size_t>(ri)];
        }
        --components;
        return true;
    }
};

int maxNumEdgesToRemove(int n, const std::vector<std::vector<int>>& edges) {
    DSU alice(n);
    DSU bob(n);
    int used = 0;
    // type 3 first (shared)
    for (const auto& e : edges) {
        if (e[0] == 3) {
            const bool ua = alice.unite(e[1], e[2]);
            const bool ub = bob.unite(e[1], e[2]);
            if (ua || ub) {
                ++used;
            }
        }
    }
    for (const auto& e : edges) {
        if (e[0] == 1) {
            if (alice.unite(e[1], e[2])) {
                ++used;
            }
        } else if (e[0] == 2) {
            if (bob.unite(e[1], e[2])) {
                ++used;
            }
        }
    }
    if (alice.components != 1 || bob.components != 1) {
        return -1;
    }
    return static_cast<int>(edges.size()) - used;
}

int main() {
    const std::vector<std::vector<int>> edges = {
        {3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
    std::cout << maxNumEdgesToRemove(4, edges) << " (expected 2)\n";
    return 0;
}
