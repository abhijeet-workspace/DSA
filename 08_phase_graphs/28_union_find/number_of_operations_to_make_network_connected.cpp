// Number of Operations to Make Network Connected — LeetCode 1319
// Min operations to connect n computers; move existing spare cables.
#include <iostream>
#include <numeric>
#include <vector>

struct DSU {
    std::vector<int> parent;
    std::vector<int> rank;
    int components;
    int extra; // redundant edges within a component
    explicit DSU(int n)
        : parent(static_cast<size_t>(n)),
          rank(static_cast<size_t>(n), 1),
          components(n),
          extra(0) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[static_cast<size_t>(i)] == i) {
            return i;
        }
        return parent[static_cast<size_t>(i)] = find(parent[static_cast<size_t>(i)]);
    }
    void unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri == rj) {
            ++extra;
            return;
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
    }
};

int makeConnected(int n, const std::vector<std::vector<int>>& connections) {
    if (static_cast<int>(connections.size()) < n - 1) {
        return -1; // not enough cables
    }
    DSU dsu(n);
    for (const auto& e : connections) {
        dsu.unite(e[0], e[1]);
    }
    // need components-1 moves; extras guarantee availability when |E|>=n-1
    return dsu.components - 1;
}

int main() {
    std::cout << makeConnected(4, {{0, 1}, {0, 2}, {1, 2}}) << " (expected 1)\n";
    std::cout << makeConnected(6, {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}})
              << " (expected 2)\n";
    return 0;
}
