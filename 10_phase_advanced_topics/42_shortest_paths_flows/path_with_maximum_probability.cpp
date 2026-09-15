// Path with Maximum Probability — https://leetcode.com/problems/path-with-maximum-probability/
// Dijkstra maximizing product of success probabilities along the path.
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

double maxProbability(int n, const std::vector<std::vector<int>>& edges,
                      const std::vector<double>& succProb, int start, int end) {
    std::vector<std::vector<std::pair<int, double>>> g(static_cast<size_t>(n));
    for (size_t i = 0; i < edges.size(); ++i) {
        const int a = edges[i][0];
        const int b = edges[i][1];
        const double p = succProb[i];
        g[static_cast<size_t>(a)].push_back({b, p});
        g[static_cast<size_t>(b)].push_back({a, p});
    }
    std::vector<double> best(static_cast<size_t>(n), 0.0);
    best[static_cast<size_t>(start)] = 1.0;
    std::priority_queue<std::pair<double, int>> pq; // max-heap by probability
    pq.push({1.0, start});
    while (!pq.empty()) {
        const auto [prob, u] = pq.top();
        pq.pop();
        if (prob < best[static_cast<size_t>(u)]) {
            continue;
        }
        if (u == end) {
            return prob;
        }
        for (const auto& [v, w] : g[static_cast<size_t>(u)]) {
            const double np = prob * w;
            if (np > best[static_cast<size_t>(v)]) {
                best[static_cast<size_t>(v)] = np;
                pq.push({np, v});
            }
        }
    }
    return 0.0;
}

int main() {
    const std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    const std::vector<double> prob = {0.5, 0.5, 0.2};
    std::cout << std::fixed << std::setprecision(5) << maxProbability(3, edges, prob, 0, 2)
              << " (expected 0.25000)\n";
    return 0;
}
