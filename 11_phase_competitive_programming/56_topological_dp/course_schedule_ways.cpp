// Course Schedule Ways — related to LC 207/210; CP path-counting DP
// Count distinct paths from sources to a sink on a DAG (topo DP).
#include <iostream>
#include <queue>
#include <vector>

long long waysToSink(int n, const std::vector<std::vector<int>>& g, int sink) {
    std::vector<int> indeg(n, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : g[static_cast<size_t>(u)]) ++indeg[static_cast<size_t>(v)];
    }
    std::vector<long long> ways(n, 0);
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indeg[static_cast<size_t>(i)] == 0) {
            ways[static_cast<size_t>(i)] = 1; // each source seeds one prefix
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[static_cast<size_t>(u)]) {
            ways[static_cast<size_t>(v)] += ways[static_cast<size_t>(u)];
            if (--indeg[static_cast<size_t>(v)] == 0) q.push(v);
        }
    }
    return ways[static_cast<size_t>(sink)];
}

int main() {
    int n = 4;
    std::vector<std::vector<int>> g(n);
    g[0].push_back(2);
    g[1].push_back(2);
    g[2].push_back(3);
    std::cout << "ways_to_3=" << waysToSink(n, g, 3) << " (expected 2)\n";

    std::vector<std::vector<int>> g2(4);
    g2[0].push_back(1);
    g2[0].push_back(2);
    g2[1].push_back(3);
    g2[2].push_back(3);
    std::cout << "diamond_ways=" << waysToSink(4, g2, 3) << " (expected 2)\n";
    return 0;
}
