// Cheapest Flights Within K Stops — LeetCode 787
// Bellman-Ford limited to at most K+1 edges (K stops).
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst,
                      int k) {
    std::vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i <= k; ++i) {
        std::vector<int> nd = dist;
        for (const auto& f : flights) {
            if (dist[f[0]] != INT_MAX) {
                nd[f[1]] = std::min(nd[f[1]], dist[f[0]] + f[2]);
            }
        }
        dist.swap(nd);
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    std::vector<std::vector<int>> f = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    std::cout << findCheapestPrice(3, f, 0, 2, 1) << " (expected 200)\n";
    return 0;
}
