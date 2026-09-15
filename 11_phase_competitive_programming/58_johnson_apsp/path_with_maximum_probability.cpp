// Path with Maximum Probability — LeetCode 1514
#include <iostream>
#include <queue>
#include <vector>

double maxProbability(int n, const std::vector<std::vector<int>>& edges,
                      const std::vector<double>& succProb, int start, int end) {
    std::vector<std::vector<std::pair<int, double>>> g(n);
    for (size_t i = 0; i < edges.size(); ++i) {
        int u = edges[i][0], v = edges[i][1];
        g[u].push_back({v, succProb[i]});
        g[v].push_back({u, succProb[i]});
    }
    std::vector<double> best(n, 0.0);
    using P = std::pair<double, int>;
    std::priority_queue<P> pq;
    best[start] = 1.0;
    pq.push({1.0, start});
    while (!pq.empty()) {
        auto [p, u] = pq.top();
        pq.pop();
        if (p != best[u])
            continue;
        if (u == end)
            return p;
        for (auto [v, w] : g[u]) {
            double np = p * w;
            if (np > best[v]) {
                best[v] = np;
                pq.push({np, v});
            }
        }
    }
    return 0.0;
}

int main() {
    double ans = maxProbability(3, {{0, 1}, {1, 2}, {0, 2}}, {0.5, 0.5, 0.2}, 0, 2);
    std::cout << ans << " (expected 0.25)\n";
    return 0;
}
