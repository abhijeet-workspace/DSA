// Number of Provinces — https://leetcode.com/problems/number-of-provinces/
// Count connected components in an undirected graph given as adjacency matrix.
#include <iostream>
#include <numeric>
#include <vector>

struct DSU {
    std::vector<int> parent;
    std::vector<int> rank;
    int components;
    explicit DSU(int n)
        : parent(static_cast<size_t>(n)), rank(static_cast<size_t>(n), 1), components(n) {
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

int findCircleNum(const std::vector<std::vector<int>>& isConnected) {
    const int n = static_cast<int>(isConnected.size());
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isConnected[static_cast<size_t>(i)][static_cast<size_t>(j)]) {
                dsu.unite(i, j);
            }
        }
    }
    return dsu.components;
}

int main() {
    const std::vector<std::vector<int>> g = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    std::cout << findCircleNum(g) << " (expected 2)\n";
    return 0;
}
