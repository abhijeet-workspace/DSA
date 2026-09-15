// Parallel Courses III — LeetCode 2050
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int minimumTime(int n, const std::vector<std::vector<int>>& relations,
                const std::vector<int>& time) {
    std::vector<std::vector<int>> g(static_cast<size_t>(n) + 1);
    std::vector<int> indeg(static_cast<size_t>(n) + 1, 0);
    for (const auto& r : relations) {
        g[static_cast<size_t>(r[0])].push_back(r[1]);
        ++indeg[static_cast<size_t>(r[1])];
    }
    std::vector<int> dist(static_cast<size_t>(n) + 1, 0);
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        dist[static_cast<size_t>(i)] = time[static_cast<size_t>(i - 1)];
        if (indeg[static_cast<size_t>(i)] == 0)
            q.push(i);
    }
    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans = std::max(ans, dist[static_cast<size_t>(u)]);
        for (int v : g[static_cast<size_t>(u)]) {
            dist[static_cast<size_t>(v)] =
                std::max(dist[static_cast<size_t>(v)],
                         dist[static_cast<size_t>(u)] + time[static_cast<size_t>(v - 1)]);
            if (--indeg[static_cast<size_t>(v)] == 0)
                q.push(v);
        }
    }
    return ans;
}

int main() {
    std::cout << minimumTime(3, {{1, 3}, {2, 3}}, {3, 2, 5}) << " (expected 8)\n";
    return 0;
}
