// DAG Count Paths — CP classic
#include <iostream>
#include <queue>
#include <vector>

long long countPaths(int n, int src, int sink, const std::vector<std::vector<int>>& g) {
    std::vector<int> indeg(static_cast<size_t>(n) + 1, 0);
    for (int u = 1; u <= n; ++u)
        for (int v : g[static_cast<size_t>(u)])
            ++indeg[static_cast<size_t>(v)];
    std::vector<long long> ways(static_cast<size_t>(n) + 1, 0);
    ways[static_cast<size_t>(src)] = 1;
    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indeg[static_cast<size_t>(i)] == 0)
            q.push(i);
    // process all; sources other than src keep ways 0
    std::vector<int> indeg2 = indeg;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[static_cast<size_t>(u)]) {
            ways[static_cast<size_t>(v)] += ways[static_cast<size_t>(u)];
            if (--indeg2[static_cast<size_t>(v)] == 0)
                q.push(v);
        }
    }
    return ways[static_cast<size_t>(sink)];
}

int main() {
    std::vector<std::vector<int>> g(5);
    g[1] = {2, 3};
    g[2] = {4};
    g[3] = {4};
    std::cout << countPaths(4, 1, 4, g) << " (expected 2)\n";
    return 0;
}
