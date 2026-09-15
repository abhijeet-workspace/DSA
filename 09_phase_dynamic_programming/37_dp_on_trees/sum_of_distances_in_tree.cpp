// Sum of Distances in Tree — https://leetcode.com/problems/sum-of-distances-in-tree/
#include <functional>
#include <iostream>
#include <vector>

std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> g(n);
    for (auto& e : edges) {
        g[static_cast<size_t>(e[0])].push_back(e[1]);
        g[static_cast<size_t>(e[1])].push_back(e[0]);
    }
    std::vector<int> count(n, 1), ans(n, 0);
    std::function<void(int, int)> dfs1 = [&](int u, int p) {
        for (int v : g[static_cast<size_t>(u)]) if (v != p) {
            dfs1(v, u);
            count[static_cast<size_t>(u)] += count[static_cast<size_t>(v)];
            ans[static_cast<size_t>(u)] += ans[static_cast<size_t>(v)] + count[static_cast<size_t>(v)];
        }
    };
    std::function<void(int, int)> dfs2 = [&](int u, int p) {
        for (int v : g[static_cast<size_t>(u)]) if (v != p) {
            ans[static_cast<size_t>(v)] = ans[static_cast<size_t>(u)] - count[static_cast<size_t>(v)] +
                                          (n - count[static_cast<size_t>(v)]);
            dfs2(v, u);
        }
    };
    dfs1(0, -1);
    dfs2(0, -1);
    return ans;
}

int main() {
    std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    for (int x : sumOfDistancesInTree(6, edges)) std::cout << x << ' ';
    std::cout << "(expected 8 12 6 10 10 10)\n";
    return 0;
}
