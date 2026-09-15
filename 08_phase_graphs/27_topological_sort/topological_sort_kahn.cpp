// Topological Sort (Kahn) — classic BFS indegree algorithm (DAG).
// Related teaching for Course Schedule / Alien Dictionary style problems.
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> kahn(int n, const std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> g(static_cast<size_t>(n));
    std::vector<int> indeg(static_cast<size_t>(n), 0);
    for (const auto& e : edges) {
        g[static_cast<size_t>(e[0])].push_back(e[1]);
        ++indeg[static_cast<size_t>(e[1])];
    }
    std::queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indeg[static_cast<size_t>(i)] == 0) q.push(i);
    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[static_cast<size_t>(u)])
            if (--indeg[static_cast<size_t>(v)] == 0) q.push(v);
    }
    if (static_cast<int>(order.size()) != n) return {}; // cycle
    return order;
}

int main() {
    const auto o = kahn(4, {{0, 1}, {0, 2}, {1, 3}, {2, 3}});
    std::cout << "order size=" << o.size() << " (expected 4)\n";
    for (int x : o) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
