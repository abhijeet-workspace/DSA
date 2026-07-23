// Redundant Connection — https://leetcode.com/problems/redundant-connection/
// Return the edge that creates a cycle in an otherwise tree-like graph.
#include <iostream>
#include <numeric>
#include <vector>

struct DSU {
    std::vector<int> parent;
    std::vector<int> rank;
    explicit DSU(int n)
        : parent(static_cast<size_t>(n)), rank(static_cast<size_t>(n), 1) {
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
            return false; // already connected → cycle edge
        }
        if (rank[static_cast<size_t>(ri)] < rank[static_cast<size_t>(rj)]) {
            parent[static_cast<size_t>(ri)] = rj;
        } else if (rank[static_cast<size_t>(ri)] > rank[static_cast<size_t>(rj)]) {
            parent[static_cast<size_t>(rj)] = ri;
        } else {
            parent[static_cast<size_t>(rj)] = ri;
            ++rank[static_cast<size_t>(ri)];
        }
        return true;
    }
};

std::vector<int> findRedundantConnection(const std::vector<std::vector<int>>& edges) {
    DSU dsu(static_cast<int>(edges.size()) + 1); // nodes are 1-indexed
    for (const auto& edge : edges) {
        if (!dsu.unite(edge[0], edge[1])) {
            return edge;
        }
    }
    return {};
}

int main() {
    const std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    const auto red = findRedundantConnection(edges);
    std::cout << "redundant: [" << red[0] << ", " << red[1] << "] (expected [1, 4])\n";
    return 0;
}
