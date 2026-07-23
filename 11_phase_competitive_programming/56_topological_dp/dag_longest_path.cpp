// DAG Longest Path — CP classic / scheduling on DAGs
// Maximum path weight on a DAG (unit or weighted edges) via topo DP.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Edge {
    int to;
    long long w;
};

long long longestPathDAG(int n, const std::vector<std::vector<Edge>>& g) {
    std::vector<int> indeg(static_cast<size_t>(n) + 1, 0);
    for (int u = 1; u <= n; ++u)
        for (const Edge& e : g[static_cast<size_t>(u)]) ++indeg[static_cast<size_t>(e.to)];

    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indeg[static_cast<size_t>(i)] == 0) q.push(i);

    std::vector<long long> dp(static_cast<size_t>(n) + 1, 0);
    long long best = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        best = std::max(best, dp[static_cast<size_t>(u)]);
        for (const Edge& e : g[static_cast<size_t>(u)]) {
            dp[static_cast<size_t>(e.to)] =
                std::max(dp[static_cast<size_t>(e.to)], dp[static_cast<size_t>(u)] + e.w);
            if (--indeg[static_cast<size_t>(e.to)] == 0) q.push(e.to);
        }
    }
    return best;
}

int main() {
    std::vector<std::vector<Edge>> g(5);
    g[1].push_back({2, 1});
    g[2].push_back({4, 1});
    g[1].push_back({3, 1});
    g[3].push_back({4, 1});
    std::cout << "longest_unit=" << longestPathDAG(4, g) << " (expected 2)\n";

    std::vector<std::vector<Edge>> g2(4);
    g2[1].push_back({2, 5});
    g2[2].push_back({3, 1});
    g2[1].push_back({3, 3});
    std::cout << "longest_weighted=" << longestPathDAG(3, g2) << " (expected 6)\n";
    return 0;
}
