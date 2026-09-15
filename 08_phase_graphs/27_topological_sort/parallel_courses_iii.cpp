// Parallel Courses III — https://leetcode.com/problems/parallel-courses-iii/
// Min months to finish all courses with prerequisites; time[i] months each; unlimited parallel.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int minimumTime(int n, const std::vector<std::vector<int>>& relations,
                const std::vector<int>& time) {
    std::vector<std::vector<int>> adj(static_cast<size_t>(n + 1));
    std::vector<int> indeg(static_cast<size_t>(n + 1), 0);
    for (const auto& r : relations) {
        adj[static_cast<size_t>(r[0])].push_back(r[1]);
        ++indeg[static_cast<size_t>(r[1])];
    }
    std::vector<int> dist(static_cast<size_t>(n + 1), 0);
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indeg[static_cast<size_t>(i)] == 0) {
            dist[static_cast<size_t>(i)] = time[static_cast<size_t>(i - 1)];
            q.push(i);
        }
    }
    while (!q.empty()) {
        const int u = q.front();
        q.pop();
        for (int v : adj[static_cast<size_t>(u)]) {
            dist[static_cast<size_t>(v)] =
                std::max(dist[static_cast<size_t>(v)],
                         dist[static_cast<size_t>(u)] + time[static_cast<size_t>(v - 1)]);
            if (--indeg[static_cast<size_t>(v)] == 0) {
                q.push(v);
            }
        }
    }
    return *std::max_element(dist.begin(), dist.end());
}

int main() {
    std::cout << minimumTime(3, {{1, 3}, {2, 3}}, {3, 2, 5}) << " (expected 8)\n";
    std::cout << minimumTime(5, {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}}, {1, 2, 3, 4, 5})
              << " (expected 12)\n";
    return 0;
}
