// Kruskal MST — classic greedy MST via sorted edges + DSU.
// Return total weight of a minimum spanning tree on V vertices.
#include <algorithm>
#include <iostream>
#include <vector>

struct Edge {
    int u;
    int v;
    int weight;
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

struct UnionFind {
    std::vector<int> parent;
    std::vector<int> rank;
    explicit UnionFind(int n)
        : parent(static_cast<size_t>(n)), rank(static_cast<size_t>(n), 0) {
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
    bool unionSets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (rank[static_cast<size_t>(a)] < rank[static_cast<size_t>(b)]) {
            parent[static_cast<size_t>(a)] = b;
        } else if (rank[static_cast<size_t>(a)] > rank[static_cast<size_t>(b)]) {
            parent[static_cast<size_t>(b)] = a;
        } else {
            parent[static_cast<size_t>(b)] = a;
            ++rank[static_cast<size_t>(a)];
        }
        return true;
    }
};

int getMSTWeight(int V, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end()); // lightest edges first
    UnionFind uf(V);
    int mstWeight = 0;
    int edgesUsed = 0;
    for (const Edge& edge : edges) {
        if (uf.unionSets(edge.u, edge.v)) {
            mstWeight += edge.weight;
            if (++edgesUsed == V - 1) {
                break; // spanning tree complete
            }
        }
    }
    return mstWeight;
}

int main() {
    int V = 4;
    std::vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4},
    };
    std::cout << "MST weight: " << getMSTWeight(V, edges)
              << " (expected 19)\n";
    return 0;
}
