// Path with Maximum Probability — https://leetcode.com/problems/path-with-maximum-probability/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

double maxProbability(int n, const std::vector<std::vector<int>>& edges,
                      const std::vector<double>& succProb, int start, int end) {
    std::vector<std::vector<std::pair<int, double>>> g(static_cast<size_t>(n));
    for (size_t i = 0; i < edges.size(); ++i) {
        int a = edges[i][0], b = edges[i][1];
        g[static_cast<size_t>(a)].push_back({b, succProb[i]});
        g[static_cast<size_t>(b)].push_back({a, succProb[i]});
    }
    std::vector<double> best(static_cast<size_t>(n), 0.0);
    using P = std::pair<double, int>;
    std::priority_queue<P> pq; // max heap on probability
    best[static_cast<size_t>(start)] = 1.0;
    pq.push({1.0, start});
    while (!pq.empty()) {
        auto [p, u] = pq.top();
        pq.pop();
        if (p != best[static_cast<size_t>(u)])
            continue;
        if (u == end)
            return p;
        for (auto [v, w] : g[static_cast<size_t>(u)]) {
            double np = p * w;
            if (np > best[static_cast<size_t>(v)]) {
                best[static_cast<size_t>(v)] = np;
                pq.push({np, v});
            }
        }
    }
    return 0.0;
}

int main() {
    std::cout << maxProbability(3, {{0, 1}, {1, 2}, {0, 2}}, {0.5, 0.5, 0.2}, 0, 2)
              << " (expected 0.25)\n";
    return 0;
}
