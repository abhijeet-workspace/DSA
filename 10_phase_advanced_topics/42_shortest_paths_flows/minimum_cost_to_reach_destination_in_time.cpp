// Minimum Cost to Reach Destination in Time — LeetCode 1928
// Dijkstra on state (node, time); minimize sum of passing fees with time ≤ maxTime.
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int minCost(int maxTime, const std::vector<std::vector<int>>& edges,
            const std::vector<int>& passingFee) {
    const int n = static_cast<int>(passingFee.size());
    const int INF = 1e9;
    std::vector<std::vector<std::pair<int, int>>> g(static_cast<size_t>(n));
    for (const auto& e : edges) {
        g[static_cast<size_t>(e[0])].push_back({e[1], e[2]});
        g[static_cast<size_t>(e[1])].push_back({e[0], e[2]});
    }
    // dist[u][t] = min fee to reach u with exactly time t
    std::vector<std::vector<int>> dist(static_cast<size_t>(n),
                                       std::vector<int>(static_cast<size_t>(maxTime + 1), INF));
    dist[0][0] = passingFee[0];
    using State = std::tuple<int, int, int>; // fee, time, node
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
    pq.push({passingFee[0], 0, 0});
    while (!pq.empty()) {
        const auto [fee, time, u] = pq.top();
        pq.pop();
        if (fee > dist[static_cast<size_t>(u)][static_cast<size_t>(time)]) {
            continue;
        }
        if (u == n - 1) {
            return fee;
        }
        for (const auto& [v, w] : g[static_cast<size_t>(u)]) {
            const int nt = time + w;
            if (nt > maxTime) {
                continue;
            }
            const int nf = fee + passingFee[static_cast<size_t>(v)];
            if (nf < dist[static_cast<size_t>(v)][static_cast<size_t>(nt)]) {
                dist[static_cast<size_t>(v)][static_cast<size_t>(nt)] = nf;
                pq.push({nf, nt, v});
            }
        }
    }
    return -1;
}

int main() {
    const std::vector<std::vector<int>> edges = {{0, 1, 10}, {1, 2, 10}, {2, 5, 10},
                                                 {0, 3, 1},  {3, 4, 10}, {4, 5, 15}};
    const std::vector<int> fee = {5, 1, 2, 20, 20, 3};
    std::cout << minCost(30, edges, fee) << " (expected 11)\n";
    std::cout << minCost(29, edges, fee) << " (expected 48)\n";
    std::cout << minCost(25, edges, fee) << " (expected -1)\n";
    return 0;
}
