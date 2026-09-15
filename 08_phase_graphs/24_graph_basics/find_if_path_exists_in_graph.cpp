// Find if Path Exists in Graph — https://leetcode.com/problems/find-if-path-exists-in-graph/
// Undirected graph: return true if path from source to destination exists.
#include <iostream>
#include <queue>
#include <vector>

bool validPath(int n, const std::vector<std::vector<int>>& edges, int source, int destination) {
    if (source == destination)
        return true;
    std::vector<std::vector<int>> adj(static_cast<size_t>(n));
    for (const auto& e : edges) {
        adj[static_cast<size_t>(e[0])].push_back(e[1]);
        adj[static_cast<size_t>(e[1])].push_back(e[0]);
    }
    std::vector<char> vis(static_cast<size_t>(n), 0);
    std::queue<int> q;
    q.push(source);
    vis[static_cast<size_t>(source)] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[static_cast<size_t>(u)]) {
            if (vis[static_cast<size_t>(v)])
                continue;
            if (v == destination)
                return true;
            vis[static_cast<size_t>(v)] = 1;
            q.push(v);
        }
    }
    return false;
}

int main() {
    std::cout << std::boolalpha << validPath(3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2)
              << " (expected true)\n";
    std::cout << validPath(6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5)
              << " (expected false)\n";
    return 0;
}
