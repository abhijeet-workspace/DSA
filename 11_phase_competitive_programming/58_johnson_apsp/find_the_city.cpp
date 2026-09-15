// Find the City With the Smallest Number of Neighbors — LeetCode 1334
#include <algorithm>
#include <iostream>
#include <vector>

int findTheCity(int n, const std::vector<std::vector<int>>& edges, int distanceThreshold) {
    const int INF = 1e9;
    std::vector<std::vector<int>> d(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;
    for (const auto& e : edges) {
        d[e[0]][e[1]] = e[2];
        d[e[1]][e[0]] = e[2];
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    int bestCity = 0, bestCnt = n;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
            if (i != j && d[i][j] <= distanceThreshold)
                ++cnt;
        if (cnt <= bestCnt) {
            bestCnt = cnt;
            bestCity = i;
        }
    }
    return bestCity;
}

int main() {
    std::cout << findTheCity(4, {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}}, 4)
              << " (expected 3)\n";
    return 0;
}
