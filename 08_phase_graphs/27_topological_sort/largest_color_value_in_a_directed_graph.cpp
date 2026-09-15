// Largest Color Value in a Directed Graph
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int largestPathValue(const std::string& colors, const std::vector<std::vector<int>>& edges) {
    const int n = static_cast<int>(colors.size());
    std::vector<std::vector<int>> g(static_cast<size_t>(n));
    std::vector<int> indeg(static_cast<size_t>(n), 0);
    for (const auto& e : edges) {
        g[static_cast<size_t>(e[0])].push_back(e[1]);
        ++indeg[static_cast<size_t>(e[1])];
    }
    std::vector<std::vector<int>> dp(static_cast<size_t>(n), std::vector<int>(26, 0));
    std::queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indeg[static_cast<size_t>(i)] == 0) q.push(i);
    int seen = 0, ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++seen;
        dp[static_cast<size_t>(u)][colors[static_cast<size_t>(u)] - 'a']++;
        ans = std::max(ans, dp[static_cast<size_t>(u)][colors[static_cast<size_t>(u)] - 'a']);
        for (int v : g[static_cast<size_t>(u)]) {
            for (int c = 0; c < 26; ++c)
                dp[static_cast<size_t>(v)][c] =
                    std::max(dp[static_cast<size_t>(v)][c], dp[static_cast<size_t>(u)][c]);
            if (--indeg[static_cast<size_t>(v)] == 0) q.push(v);
        }
    }
    return seen == n ? ans : -1;
}

int main() {
    std::cout << largestPathValue("abaca", {{0, 1}, {0, 2}, {2, 3}, {3, 4}}) << " (expected 3)\n";
    return 0;
}
