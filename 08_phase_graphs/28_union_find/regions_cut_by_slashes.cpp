// Regions Cut By Slashes — https://leetcode.com/problems/regions-cut-by-slashes/
// Split each cell into 4 triangles; union across empty edges; count DSU components.
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct DSU {
    std::vector<int> parent;
    int components;
    explicit DSU(int n) : parent(static_cast<size_t>(n)), components(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[static_cast<size_t>(x)] != x) {
            parent[static_cast<size_t>(x)] = find(parent[static_cast<size_t>(x)]);
        }
        return parent[static_cast<size_t>(x)];
    }
    void unite(int a, int b) {
        const int ra = find(a);
        const int rb = find(b);
        if (ra == rb) {
            return;
        }
        parent[static_cast<size_t>(ra)] = rb;
        --components;
    }
};

int regionsBySlashes(const std::vector<std::string>& grid) {
    const int n = static_cast<int>(grid.size());
    // 4 triangles per cell: 0=N, 1=E, 2=S, 3=W
    DSU dsu(n * n * 4);
    auto id = [n](int r, int c, int t) { return (r * n + c) * 4 + t; };

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            const char ch = grid[static_cast<size_t>(r)][static_cast<size_t>(c)];
            const int base = id(r, c, 0);
            if (ch == ' ') {
                dsu.unite(base + 0, base + 1);
                dsu.unite(base + 1, base + 2);
                dsu.unite(base + 2, base + 3);
            } else if (ch == '/') {
                dsu.unite(base + 0, base + 3); // N-W
                dsu.unite(base + 1, base + 2); // E-S
            } else { // '\\'
                dsu.unite(base + 0, base + 1); // N-E
                dsu.unite(base + 2, base + 3); // S-W
            }
            // merge with right neighbor: E of this <-> W of right
            if (c + 1 < n) {
                dsu.unite(base + 1, id(r, c + 1, 3));
            }
            // merge with bottom neighbor: S of this <-> N of below
            if (r + 1 < n) {
                dsu.unite(base + 2, id(r + 1, c, 0));
            }
        }
    }
    return dsu.components;
}

int main() {
    std::cout << regionsBySlashes({" /", "/ "}) << " (expected 2)\n"
              << regionsBySlashes({" /", "  "}) << " (expected 1)\n"
              << regionsBySlashes({"\\/", "/\\"}) << " (expected 4)\n"
              << regionsBySlashes({"/\\", "\\/"}) << " (expected 5)\n";
    return 0;
}
