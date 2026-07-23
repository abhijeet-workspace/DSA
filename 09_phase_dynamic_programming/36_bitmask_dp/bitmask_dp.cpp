// Bitmask DP — TSP held-Karp: min tour visiting each city once, return to 0.
// State (u, mask): at city u with visited set mask.
#include <algorithm>
#include <iostream>
#include <vector>

constexpr int INF = 1'000'000'000;

int tsp(const std::vector<std::vector<int>>& dist, int mask, int u, int V,
        std::vector<std::vector<int>>& memo) {
    if (mask == (1 << V) - 1) {
        return dist[static_cast<size_t>(u)][0]; // return to origin
    }
    if (memo[static_cast<size_t>(u)][static_cast<size_t>(mask)] != -1) {
        return memo[static_cast<size_t>(u)][static_cast<size_t>(mask)];
    }
    int best = INF;
    for (int v = 0; v < V; ++v) {
        if ((mask & (1 << v)) == 0) {
            const int cost = dist[static_cast<size_t>(u)][static_cast<size_t>(v)] +
                             tsp(dist, mask | (1 << v), v, V, memo);
            best = std::min(best, cost);
        }
    }
    return memo[static_cast<size_t>(u)][static_cast<size_t>(mask)] = best;
}

int solveTSP(const std::vector<std::vector<int>>& dist) {
    const int V = static_cast<int>(dist.size());
    std::vector<std::vector<int>> memo(static_cast<size_t>(V),
                                       std::vector<int>(1u << V, -1));
    return tsp(dist, 1, 0, V, memo); // start at 0; bit 0 set
}

int main() {
    const std::vector<std::vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0},
    };
    std::cout << solveTSP(dist) << " (expected 85)\n";
    return 0;
}
