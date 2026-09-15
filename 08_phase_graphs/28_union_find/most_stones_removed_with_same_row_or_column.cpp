// Most Stones Removed with Same Row or Column —
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/ Union row/col nodes
// per stone; removable = n - connected components.
#include <iostream>
#include <unordered_map>
#include <vector>

struct DSU {
    std::unordered_map<int, int> parent;
    int components = 0;

    int find(int x) {
        auto it = parent.find(x);
        if (it == parent.end()) {
            parent[x] = x;
            ++components;
            return x;
        }
        if (it->second != x) {
            it->second = find(it->second);
        }
        return parent[x];
    }

    void unite(int a, int b) {
        const int ra = find(a);
        const int rb = find(b);
        if (ra == rb) {
            return;
        }
        parent[ra] = rb;
        --components;
    }
};

int removeStones(const std::vector<std::vector<int>>& stones) {
    DSU dsu;
    constexpr int COL_OFFSET = 10001; // separate column id space from rows
    for (const auto& s : stones) {
        dsu.unite(s[0], s[1] + COL_OFFSET);
    }
    return static_cast<int>(stones.size()) - dsu.components;
}

int main() {
    const std::vector<std::vector<int>> stones1 = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    const std::vector<std::vector<int>> stones2 = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    const std::vector<std::vector<int>> stones3 = {{0, 0}};
    std::cout << removeStones(stones1) << " (expected 5)\n"
              << removeStones(stones2) << " (expected 3)\n"
              << removeStones(stones3) << " (expected 0)\n";
    return 0;
}
