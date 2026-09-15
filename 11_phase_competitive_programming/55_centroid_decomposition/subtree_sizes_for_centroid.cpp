// Subtree Sizes for Centroid — building block
#include <iostream>
#include <vector>

void dfsSize(int v, int p, const std::vector<std::vector<int>>& g, std::vector<int>& sz) {
    sz[static_cast<size_t>(v)] = 1;
    for (int to : g[static_cast<size_t>(v)])
        if (to != p) {
            dfsSize(to, v, g, sz);
            sz[static_cast<size_t>(v)] += sz[static_cast<size_t>(to)];
        }
}

int main() {
    int n = 5;
    std::vector<std::vector<int>> g(static_cast<size_t>(n) + 1);
    auto add = [&](int u, int v) {
        g[static_cast<size_t>(u)].push_back(v);
        g[static_cast<size_t>(v)].push_back(u);
    };
    add(1, 2);
    add(1, 3);
    add(3, 4);
    add(3, 5);
    std::vector<int> sz(static_cast<size_t>(n) + 1);
    dfsSize(1, 0, g, sz);
    std::cout << "sz:";
    for (int i = 1; i <= n; ++i)
        std::cout << " " << sz[static_cast<size_t>(i)];
    std::cout << " (expected 5 1 3 1 1)\n";
    return 0;
}
