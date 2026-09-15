// Detonate the Maximum Bombs — https://leetcode.com/problems/detonate-the-maximum-bombs/
#include <iostream>
#include <vector>

long long sq(long long x) {
    return x * x;
}

int dfs(int u, const std::vector<std::vector<int>>& g, std::vector<char>& vis) {
    vis[static_cast<size_t>(u)] = 1;
    int cnt = 1;
    for (int v : g[static_cast<size_t>(u)]) {
        if (!vis[static_cast<size_t>(v)])
            cnt += dfs(v, g, vis);
    }
    return cnt;
}

int maximumDetonation(const std::vector<std::vector<int>>& bombs) {
    const int n = static_cast<int>(bombs.size());
    std::vector<std::vector<int>> g(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            long long dx = bombs[static_cast<size_t>(i)][0] - bombs[static_cast<size_t>(j)][0];
            long long dy = bombs[static_cast<size_t>(i)][1] - bombs[static_cast<size_t>(j)][1];
            long long r = bombs[static_cast<size_t>(i)][2];
            if (sq(dx) + sq(dy) <= sq(r))
                g[static_cast<size_t>(i)].push_back(j);
        }
    }
    int best = 0;
    for (int i = 0; i < n; ++i) {
        std::vector<char> vis(static_cast<size_t>(n), 0);
        best = std::max(best, dfs(i, g, vis));
    }
    return best;
}

int main() {
    std::cout << maximumDetonation({{2, 1, 3}, {6, 1, 4}}) << " (expected 2)\n";
    std::cout << maximumDetonation({{1, 1, 5}, {10, 10, 5}}) << " (expected 1)\n";
    return 0;
}
