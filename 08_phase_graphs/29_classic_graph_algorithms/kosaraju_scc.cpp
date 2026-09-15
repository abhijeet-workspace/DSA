// Kosaraju Strongly Connected Components — classic 2-pass DFS SCC algorithm.
// Related LC: https://leetcode.com/problems/critical-connections-in-a-network/ (bridges, different)
#include <algorithm>
#include <iostream>
#include <vector>

void dfs1(int u, const std::vector<std::vector<int>>& g, std::vector<char>& vis,
          std::vector<int>& order) {
    vis[static_cast<size_t>(u)] = 1;
    for (int v : g[static_cast<size_t>(u)])
        if (!vis[static_cast<size_t>(v)])
            dfs1(v, g, vis, order);
    order.push_back(u);
}

void dfs2(int u, const std::vector<std::vector<int>>& gr, std::vector<char>& vis,
          std::vector<int>& comp) {
    vis[static_cast<size_t>(u)] = 1;
    comp.push_back(u);
    for (int v : gr[static_cast<size_t>(u)])
        if (!vis[static_cast<size_t>(v)])
            dfs2(v, gr, vis, comp);
}

std::vector<std::vector<int>> kosaraju(int n, const std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> g(static_cast<size_t>(n)), gr(static_cast<size_t>(n));
    for (const auto& e : edges) {
        g[static_cast<size_t>(e[0])].push_back(e[1]);
        gr[static_cast<size_t>(e[1])].push_back(e[0]);
    }
    std::vector<char> vis(static_cast<size_t>(n), 0);
    std::vector<int> order;
    for (int i = 0; i < n; ++i)
        if (!vis[static_cast<size_t>(i)])
            dfs1(i, g, vis, order);
    std::fill(vis.begin(), vis.end(), 0);
    std::vector<std::vector<int>> sccs;
    for (int i = n - 1; i >= 0; --i) {
        int u = order[static_cast<size_t>(i)];
        if (!vis[static_cast<size_t>(u)]) {
            std::vector<int> comp;
            dfs2(u, gr, vis, comp);
            sccs.push_back(std::move(comp));
        }
    }
    return sccs;
}

int main() {
    const auto sccs = kosaraju(5, {{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}});
    std::cout << "components=" << sccs.size() << " (expected 3)\n";
    return 0;
}
