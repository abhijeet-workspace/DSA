// Union-Find basics — path compression + union by rank.
// Demo: count connected components in an undirected edge list.
#include <iostream>
#include <vector>

class UnionFind {
    std::vector<int> parent;
    std::vector<int> rank;
    int count;

public:
    explicit UnionFind(int n)
        : parent(static_cast<size_t>(n)), rank(static_cast<size_t>(n), 0), count(n) {
        for (int i = 0; i < n; ++i) {
            parent[static_cast<size_t>(i)] = i;
        }
    }

    int find(int x) {
        if (parent[static_cast<size_t>(x)] != x) {
            parent[static_cast<size_t>(x)] = find(parent[static_cast<size_t>(x)]); // compress
        }
        return parent[static_cast<size_t>(x)];
    }

    void unionSets(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) {
            return;
        }
        if (rank[static_cast<size_t>(ra)] < rank[static_cast<size_t>(rb)]) {
            parent[static_cast<size_t>(ra)] = rb;
        } else if (rank[static_cast<size_t>(ra)] > rank[static_cast<size_t>(rb)]) {
            parent[static_cast<size_t>(rb)] = ra;
        } else {
            parent[static_cast<size_t>(rb)] = ra;
            ++rank[static_cast<size_t>(ra)];
        }
        --count;
    }

    int getCount() const { return count; }
};

int countComponents(int n, const std::vector<std::vector<int>>& edges) {
    UnionFind uf(n);
    for (const auto& e : edges) {
        uf.unionSets(e[0], e[1]);
    }
    return uf.getCount();
}

int main() {
    const int n = 5;
    const std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    std::cout << "components: " << countComponents(n, edges) << " (expected 2)\n";
    return 0;
}
