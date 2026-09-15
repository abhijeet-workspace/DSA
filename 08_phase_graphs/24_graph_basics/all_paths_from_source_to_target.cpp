// All Paths From Source to Target — https://leetcode.com/problems/all-paths-from-source-to-target/
// DAG adjacency list: return all paths from node 0 to node n-1.
#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& graph, int u, int target,
         std::vector<int>& path, std::vector<std::vector<int>>& result) {
    path.push_back(u);
    if (u == target) {
        result.push_back(path);
    } else {
        for (int v : graph[static_cast<size_t>(u)]) dfs(graph, v, target, path, result);
    }
    path.pop_back();
}

std::vector<std::vector<int>> allPathsSourceTarget(const std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    dfs(graph, 0, static_cast<int>(graph.size()) - 1, path, result);
    return result;
}

int main() {
    const auto r = allPathsSourceTarget({{1, 2}, {3}, {3}, {}});
    std::cout << "count=" << r.size() << " (expected 2)\n";
    return 0;
}
