// Number of Connected Components — https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// Count components in an undirected graph via Union-Find.
#include <iostream>
#include <vector>

int countComponents(int n, const std::vector<std::vector<int>>& edges) {
    std::vector<int> parent(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        parent[static_cast<size_t>(i)] = i;
    }
    auto find = [&](auto&& self, int x) -> int {
        if (parent[static_cast<size_t>(x)] != x) {
            parent[static_cast<size_t>(x)] = self(self, parent[static_cast<size_t>(x)]);
        }
        return parent[static_cast<size_t>(x)];
    };
    int comps = n; // isolates start as their own components
    for (const auto& e : edges) {
        const int a = find(find, e[0]);
        const int b = find(find, e[1]);
        if (a != b) {
            parent[static_cast<size_t>(b)] = a;
            --comps;
        }
    }
    return comps;
}

int main() {
    std::cout << countComponents(5, {{0, 1}, {1, 2}, {3, 4}}) << " (expected 2)\n"
              << countComponents(5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}) << " (expected 1)\n";
    return 0;
}
