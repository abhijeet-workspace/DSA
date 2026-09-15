// Find the City With the Smallest Number of Neighbors at a Threshold Distance — LeetCode 1334
// Floyd-Warshall all-pairs; pick city with fewest reachable within distanceThreshold (ties → largest id).
#include <algorithm>
#include <iostream>
#include <vector>

int findTheCity(int n, const std::vector<std::vector<int>>& edges, int distanceThreshold) {
    const int INF = 1e9;
    std::vector<std::vector<int>> dist(static_cast<size_t>(n),
                                       std::vector<int>(static_cast<size_t>(n), INF));
    for (int i = 0; i < n; ++i) {
        dist[static_cast<size_t>(i)][static_cast<size_t>(i)] = 0;
    }
    for (const auto& e : edges) {
        dist[static_cast<size_t>(e[0])][static_cast<size_t>(e[1])] = e[2];
        dist[static_cast<size_t>(e[1])][static_cast<size_t>(e[0])] = e[2];
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[static_cast<size_t>(i)][static_cast<size_t>(k)] +
                        dist[static_cast<size_t>(k)][static_cast<size_t>(j)]
                    < dist[static_cast<size_t>(i)][static_cast<size_t>(j)]) {
                    dist[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                        dist[static_cast<size_t>(i)][static_cast<size_t>(k)]
                        + dist[static_cast<size_t>(k)][static_cast<size_t>(j)];
                }
            }
        }
    }
    int bestCity = -1;
    int bestCount = n;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j && dist[static_cast<size_t>(i)][static_cast<size_t>(j)] <= distanceThreshold) {
                ++cnt;
            }
        }
        if (cnt <= bestCount) {
            bestCount = cnt;
            bestCity = i; // larger id wins on ties
        }
    }
    return bestCity;
}

int main() {
    const std::vector<std::vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    std::cout << findTheCity(4, edges, 4) << " (expected 3)\n";
    return 0;
}
