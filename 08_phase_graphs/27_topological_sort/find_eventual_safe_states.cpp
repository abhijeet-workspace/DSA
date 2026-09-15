// Find Eventual Safe States — https://leetcode.com/problems/find-eventual-safe-states/
// Nodes from which every path ends in a terminal (no cycle reachable).
#include <iostream>
#include <vector>

// 0 = unvisited, 1 = visiting (on stack), 2 = safe
bool dfs(int u, const std::vector<std::vector<int>>& graph, std::vector<int>& color) {
    if (color[static_cast<size_t>(u)] != 0) {
        return color[static_cast<size_t>(u)] == 2;
    }
    color[static_cast<size_t>(u)] = 1;
    for (int v : graph[static_cast<size_t>(u)]) {
        if (!dfs(v, graph, color)) {
            return false; // cycle or leads to unsafe
        }
    }
    color[static_cast<size_t>(u)] = 2;
    return true;
}

std::vector<int> eventualSafeNodes(const std::vector<std::vector<int>>& graph) {
    const int n = static_cast<int>(graph.size());
    std::vector<int> color(static_cast<size_t>(n), 0);
    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (dfs(i, graph, color)) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    const std::vector<std::vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    const auto safe = eventualSafeNodes(graph);
    std::cout << "safe: ";
    for (int x : safe) {
        std::cout << x << " ";
    }
    std::cout << "(expected 2 4 5 6)\n";
    return 0;
}
