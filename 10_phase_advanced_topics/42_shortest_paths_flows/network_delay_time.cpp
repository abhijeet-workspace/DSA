// Network Delay Time — LeetCode 743
// Dijkstra from k; answer is max dist (or -1 if unreachable).
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (const auto& e : times) {
        g[e[0]].push_back({e[1], e[2]});
    }
    std::vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    pq.push({0, k});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (const auto& edge : g[u]) {
            int v = edge.first;
            int w = edge.second;
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INT_MAX) {
            return -1;
        }
        ans = std::max(ans, dist[i]);
    }
    return ans;
}

int main() {
    std::vector<std::vector<int>> t = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    std::cout << networkDelayTime(t, 4, 2) << " (expected 2)\n";
    return 0;
}
