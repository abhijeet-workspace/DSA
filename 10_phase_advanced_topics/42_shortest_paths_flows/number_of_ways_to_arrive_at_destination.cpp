// Number of Ways to Arrive at Destination — LeetCode 1976
// Dijkstra + count shortest paths; MOD = 1e9+7.
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int countPaths(int n, const std::vector<std::vector<int>>& roads) {
    const long long INF = 4e18;
    const int MOD = 1'000'000'007;
    std::vector<std::vector<std::pair<int, int>>> g(static_cast<size_t>(n));
    for (const auto& r : roads) {
        g[static_cast<size_t>(r[0])].push_back({r[1], r[2]});
        g[static_cast<size_t>(r[1])].push_back({r[0], r[2]});
    }
    std::vector<long long> dist(static_cast<size_t>(n), INF);
    std::vector<int> ways(static_cast<size_t>(n), 0);
    dist[0] = 0;
    ways[0] = 1;
    using Node = std::pair<long long, int>;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        const auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[static_cast<size_t>(u)]) {
            continue;
        }
        for (const auto& [v, w] : g[static_cast<size_t>(u)]) {
            const long long nd = d + w;
            if (nd < dist[static_cast<size_t>(v)]) {
                dist[static_cast<size_t>(v)] = nd;
                ways[static_cast<size_t>(v)] = ways[static_cast<size_t>(u)];
                pq.push({nd, v});
            } else if (nd == dist[static_cast<size_t>(v)]) {
                ways[static_cast<size_t>(v)] =
                    (ways[static_cast<size_t>(v)] + ways[static_cast<size_t>(u)]) % MOD;
            }
        }
    }
    return ways[static_cast<size_t>(n - 1)];
}

int main() {
    const std::vector<std::vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
                                                 {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1},
                                                 {0, 4, 5}, {4, 6, 2}};
    std::cout << countPaths(7, roads) << " (expected 4)\n";
    return 0;
}
