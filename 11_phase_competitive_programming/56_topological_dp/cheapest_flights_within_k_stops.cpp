// Cheapest Flights Within K Stops — LeetCode 787
// Bellman-Ford / DP relaxations (K+1 rounds).
#include <algorithm>
#include <iostream>
#include <vector>

int findCheapestPrice(int n, const std::vector<std::vector<int>>& flights, int src, int dst,
                      int k) {
    const int INF = 1e9;
    std::vector<int> dist(static_cast<size_t>(n), INF);
    dist[static_cast<size_t>(src)] = 0;
    for (int i = 0; i <= k; ++i) {
        std::vector<int> nd = dist;
        for (const auto& f : flights) {
            int u = f[0], v = f[1], w = f[2];
            if (dist[static_cast<size_t>(u)] < INF)
                nd[static_cast<size_t>(v)] =
                    std::min(nd[static_cast<size_t>(v)], dist[static_cast<size_t>(u)] + w);
        }
        dist.swap(nd);
    }
    return dist[static_cast<size_t>(dst)] >= INF ? -1 : dist[static_cast<size_t>(dst)];
}

int main() {
    std::cout << findCheapestPrice(
                     4, {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}}, 0, 3, 1)
              << " (expected 700)\n";
    return 0;
}
