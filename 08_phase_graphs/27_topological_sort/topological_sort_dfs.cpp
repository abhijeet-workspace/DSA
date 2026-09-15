// Topological Sort (DFS) — classic DFS finishing-time order on a DAG.
#include <algorithm>
#include <iostream>
#include <vector>

bool dfs(int u, const std::vector<std::vector<int>>& g, std::vector<int>& state, std::vector<int>& order) {
    state[static_cast<size_t>(u)] = 1; // visiting
    for (int v : g[static_cast<size_t>(u)]) {
        if (state[static_cast<size_t>(v)] == 1) return false; // cycle
        if (state[static_cast<size_t>(v)] == 0) {
            if (!dfs(v, g, state, order)) return false;
        }
    }
    state[static_cast<size_t>(u)] = 2;
    order.push_back(u); // postorder
    return true;
}

std::vector<int> topoDfs(int n, const std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> g(static_cast<size_t>(n));
    for (const auto& e : edges) g[static_cast<size_t>(e[0])].push_back(e[1]);
    std::vector<int> state(static_cast<size_t>(n), 0), order;
    for (int i = 0; i < n; ++i) {
        if (state[static_cast<size_t>(i)] == 0) {
            if (!dfs(i, g, state, order)) return {};
        }
    }
    std::reverse(order.begin(), order.end());
    return order;
}

int main() {
    const auto o = topoDfs(4, {{0, 1}, {0, 2}, {1, 3}, {2, 3}});
    std::cout << "order size=" << o.size() << " (expected 4)\n";
    for (int x : o) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
