// Mo on trees (simplified) — path distinct via Euler tour + flat Mo
// Flatten tree Euler (enter only) + remove subtree trick simplified:
// For path u-v: use in-times and standard tree Mo with two occurrences.
// Mini demo: count distinct node values on path u..v using LCA + xor-on-path style
// teaching: walk path explicitly for tiny tree and compare to "Mo tour" answers.
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // Tree values on nodes: 0:1, 1:2, 2:1, 3:3, 4:2
    // edges 0-1-3, 0-2-4
    std::vector<int> val = {1, 2, 1, 3, 2};
    std::vector<std::vector<int>> adj(5);
    auto addE = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    addE(0, 1);
    addE(1, 3);
    addE(0, 2);
    addE(2, 4);
    std::vector<int> parent(5, -1), depth(5, 0);
    std::vector<int> order;
    auto dfs = [&](auto&& self, int u, int p) -> void {
        parent[u] = p;
        for (int v : adj[u])
            if (v != p) {
                depth[v] = depth[u] + 1;
                self(self, v, u);
            }
    };
    dfs(dfs, 0, -1);
    auto lca = [&](int u, int v) {
        while (depth[u] > depth[v])
            u = parent[u];
        while (depth[v] > depth[u])
            v = parent[v];
        while (u != v) {
            u = parent[u];
            v = parent[v];
        }
        return u;
    };
    auto pathDistinct = [&](int u, int v) {
        int w = lca(u, v);
        std::vector<int> seen;
        auto walk = [&](int x) {
            while (true) {
                seen.push_back(val[x]);
                if (x == w)
                    break;
                x = parent[x];
            }
        };
        walk(u);
        walk(v);
        std::sort(seen.begin(), seen.end());
        seen.erase(std::unique(seen.begin(), seen.end()), seen.end());
        return (int)seen.size();
    };
    // queries
    std::vector<std::pair<int, int>> qs = {{3, 4}, {3, 1}, {4, 2}, {3, 3}};
    std::vector<int> answers;
    for (auto [u, v] : qs)
        answers.push_back(pathDistinct(u, v));
    const std::vector<int> expected = {3, 2, 2, 1}; // 3-0-2-4 values 3,2,1,2 -> {1,2,3}; etc.
    // verify 3-4: path 3-1-0-2-4 vals 3,2,1,1,2 -> {1,2,3}=3
    // 3-1: 3,2 -> {2,3}=2
    // 4-2: 4,2 -> {2,1}=2
    // 3-3: {3}=1
    bool ok = answers == expected;
    std::cout << "answers:";
    for (int x : answers)
        std::cout << " " << x;
    std::cout << "\nexpected: 3 2 2 1\n" << (ok ? "OK\n" : "FAIL\n");
    std::cout << "note: full tree-Mo uses Euler tour + remove-on-second-visit; this lab validates "
                 "path distinct oracle.\n";
    return ok ? 0 : 1;
}
