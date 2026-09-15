// Is Graph Bipartite — LeetCode 785
#include <iostream>
#include <queue>
#include <vector>

bool isBipartite(const std::vector<std::vector<int>>& graph) {
    int n = static_cast<int>(graph.size());
    std::vector<int> color(static_cast<size_t>(n), -1);
    for (int s = 0; s < n; ++s) {
        if (color[static_cast<size_t>(s)] != -1)
            continue;
        std::queue<int> q;
        q.push(s);
        color[static_cast<size_t>(s)] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[static_cast<size_t>(u)]) {
                if (color[static_cast<size_t>(v)] == -1) {
                    color[static_cast<size_t>(v)] = color[static_cast<size_t>(u)] ^ 1;
                    q.push(v);
                } else if (color[static_cast<size_t>(v)] == color[static_cast<size_t>(u)])
                    return false;
            }
        }
    }
    return true;
}

int main() {
    std::cout << isBipartite({{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}) << " (expected 0)\n";
    std::cout << isBipartite({{1, 3}, {0, 2}, {1, 3}, {0, 2}}) << " (expected 1)\n";
    return 0;
}
