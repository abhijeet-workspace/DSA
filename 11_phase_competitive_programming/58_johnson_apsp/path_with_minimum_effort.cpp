// Path With Minimum Effort — LeetCode 1631
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

int minimumEffortPath(const std::vector<std::vector<int>>& heights) {
    int R = static_cast<int>(heights.size()), C = static_cast<int>(heights[0].size());
    const int INF = 1e9;
    std::vector<std::vector<int>> dist(R, std::vector<int>(C, INF));
    using T = std::tuple<int, int, int>;
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    const int di[4] = {1, -1, 0, 0};
    const int dj[4] = {0, 0, 1, -1};
    while (!pq.empty()) {
        auto [d, i, j] = pq.top();
        pq.pop();
        if (d != dist[i][j])
            continue;
        if (i == R - 1 && j == C - 1)
            return d;
        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= R || nj >= C)
                continue;
            int nd = std::max(d, std::abs(heights[i][j] - heights[ni][nj]));
            if (nd < dist[ni][nj]) {
                dist[ni][nj] = nd;
                pq.push({nd, ni, nj});
            }
        }
    }
    return 0;
}

int main() {
    std::cout << minimumEffortPath({{1, 2, 2}, {3, 8, 2}, {5, 3, 5}}) << " (expected 2)\n";
    return 0;
}
