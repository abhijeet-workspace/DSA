// Largest Color Value in a Directed Graph — LeetCode 1857
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int largestPathValue(const std::string& colors, const std::vector<std::vector<int>>& edges) {
    int n = static_cast<int>(colors.size());
    std::vector<std::vector<int>> g(static_cast<size_t>(n));
    std::vector<int> indeg(static_cast<size_t>(n), 0);
    for (const auto& e : edges) {
        g[static_cast<size_t>(e[0])].push_back(e[1]);
        ++indeg[static_cast<size_t>(e[1])];
    }
    std::vector<std::vector<int>> dp(static_cast<size_t>(n), std::vector<int>(26, 0));
    std::queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indeg[static_cast<size_t>(i)] == 0)
            q.push(i);
    int seen = 0, best = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++seen;
        int c = colors[static_cast<size_t>(u)] - 'a';
        ++dp[static_cast<size_t>(u)][static_cast<size_t>(c)];
        best = std::max(best, dp[static_cast<size_t>(u)][static_cast<size_t>(c)]);
        for (int v : g[static_cast<size_t>(u)]) {
            for (int k = 0; k < 26; ++k)
                dp[static_cast<size_t>(v)][static_cast<size_t>(k)] =
                    std::max(dp[static_cast<size_t>(v)][static_cast<size_t>(k)],
                             dp[static_cast<size_t>(u)][static_cast<size_t>(k)]);
            if (--indeg[static_cast<size_t>(v)] == 0)
                q.push(v);
        }
    }
    return seen == n ? best : -1;
}

int main() {
    std::cout << largestPathValue("abaca", {{0, 1}, {0, 2}, {2, 3}, {3, 4}}) << " (expected 3)\n";
    std::cout << largestPathValue("a", {{0, 0}}) << " (expected -1)\n";
    return 0;
}
