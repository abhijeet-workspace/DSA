// Find the City With the Smallest Number of Neighbors at a Threshold Distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
#include <algorithm>
#include <iostream>
#include <vector>

int findTheCity(int n, const std::vector<std::vector<int>>& edges, int distanceThreshold) {
    const int INF = 1e9;
    std::vector<std::vector<int>> dist(static_cast<size_t>(n), std::vector<int>(static_cast<size_t>(n), INF));
    for (int i = 0; i < n; ++i) dist[static_cast<size_t>(i)][static_cast<size_t>(i)] = 0;
    for (const auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        dist[static_cast<size_t>(u)][static_cast<size_t>(v)] = w;
        dist[static_cast<size_t>(v)][static_cast<size_t>(u)] = w;
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[static_cast<size_t>(i)][static_cast<size_t>(k)] +
                        dist[static_cast<size_t>(k)][static_cast<size_t>(j)] <
                    dist[static_cast<size_t>(i)][static_cast<size_t>(j)])
                    dist[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                        dist[static_cast<size_t>(i)][static_cast<size_t>(k)] +
                        dist[static_cast<size_t>(k)][static_cast<size_t>(j)];
    int bestCity = -1, bestCnt = n + 1;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
            if (i != j && dist[static_cast<size_t>(i)][static_cast<size_t>(j)] <= distanceThreshold) ++cnt;
        if (cnt <= bestCnt) {
            bestCnt = cnt;
            bestCity = i;
        }
    }
    return bestCity;
}

int main() {
    std::cout << findTheCity(4, {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}}, 4) << " (expected 3)\n";
    return 0;
}
