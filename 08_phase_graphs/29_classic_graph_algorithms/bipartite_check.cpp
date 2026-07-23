// Is Graph Bipartite — https://leetcode.com/problems/is-graph-bipartite/
// BFS 2-coloring; false if any edge joins same color.
#include <iostream>
#include <queue>
#include <vector>

bool isBipartite(const std::vector<std::vector<int>>& graph) {
    const int n = static_cast<int>(graph.size());
    std::vector<int> colors(static_cast<size_t>(n), 0); // 0 unset, ±1 sides
    for (int i = 0; i < n; ++i) {
        if (colors[static_cast<size_t>(i)] != 0) {
            continue;
        }
        std::queue<int> q;
        q.push(i);
        colors[static_cast<size_t>(i)] = 1;
        while (!q.empty()) {
            const int u = q.front();
            q.pop();
            for (int v : graph[static_cast<size_t>(u)]) {
                if (colors[static_cast<size_t>(v)] == 0) {
                    colors[static_cast<size_t>(v)] = -colors[static_cast<size_t>(u)];
                    q.push(v);
                } else if (colors[static_cast<size_t>(v)] == colors[static_cast<size_t>(u)]) {
                    return false; // odd cycle
                }
            }
        }
    }
    return true;
}

int main() {
    const std::vector<std::vector<int>> g1 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    const std::vector<std::vector<int>> g2 = {{1, 2}, {0, 2}, {0, 1}};
    std::cout << (isBipartite(g1) ? "BIPARTITE" : "NOT") << " (expected BIPARTITE)\n";
    std::cout << (isBipartite(g2) ? "BIPARTITE" : "NOT") << " (expected NOT)\n";
    return 0;
}
