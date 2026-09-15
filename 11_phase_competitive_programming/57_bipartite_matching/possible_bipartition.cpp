// Possible Bipartition — LeetCode 886
#include <iostream>
#include <queue>
#include <vector>

bool possibleBipartition(int n, const std::vector<std::vector<int>>& dislikes) {
    std::vector<std::vector<int>> g(static_cast<size_t>(n) + 1);
    for (const auto& d : dislikes) {
        g[static_cast<size_t>(d[0])].push_back(d[1]);
        g[static_cast<size_t>(d[1])].push_back(d[0]);
    }
    std::vector<int> color(static_cast<size_t>(n) + 1, -1);
    for (int s = 1; s <= n; ++s) {
        if (color[static_cast<size_t>(s)] != -1)
            continue;
        std::queue<int> q;
        q.push(s);
        color[static_cast<size_t>(s)] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[static_cast<size_t>(u)]) {
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
    std::cout << possibleBipartition(4, {{1, 2}, {1, 3}, {2, 4}}) << " (expected 1)\n";
    std::cout << possibleBipartition(3, {{1, 2}, {1, 3}, {2, 3}}) << " (expected 0)\n";
    return 0;
}
