// Reorder Routes to Make All Paths Lead to the City Zero
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
#include <iostream>
#include <vector>

void dfs(int u, const std::vector<std::vector<std::pair<int, int>>>& g, std::vector<char>& vis, int& changes) {
    vis[static_cast<size_t>(u)] = 1;
    for (const auto& [v, dir] : g[static_cast<size_t>(u)]) {
        if (vis[static_cast<size_t>(v)]) continue;
        changes += dir; // dir=1 means original edge u→v must flip to point toward 0 when rooted at 0
        dfs(v, g, vis, changes);
    }
}

int minReorder(int n, const std::vector<std::vector<int>>& connections) {
    std::vector<std::vector<std::pair<int, int>>> g(static_cast<size_t>(n));
    for (const auto& e : connections) {
        g[static_cast<size_t>(e[0])].push_back({e[1], 1});  // original direction
        g[static_cast<size_t>(e[1])].push_back({e[0], 0});  // opposite
    }
    std::vector<char> vis(static_cast<size_t>(n), 0);
    int changes = 0;
    dfs(0, g, vis, changes);
    return changes;
}

int main() {
    std::cout << minReorder(6, {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}}) << " (expected 3)\n";
    return 0;
}
