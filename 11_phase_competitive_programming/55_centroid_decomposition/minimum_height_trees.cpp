// Minimum Height Trees — LeetCode 310
// Centroids of the tree = roots yielding minimum height.
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> findMinHeightTrees(int n, const std::vector<std::vector<int>>& edges) {
    if (n == 1)
        return {0};
    std::vector<std::vector<int>> g(static_cast<size_t>(n));
    std::vector<int> deg(static_cast<size_t>(n), 0);
    for (const auto& e : edges) {
        g[static_cast<size_t>(e[0])].push_back(e[1]);
        g[static_cast<size_t>(e[1])].push_back(e[0]);
        ++deg[static_cast<size_t>(e[0])];
        ++deg[static_cast<size_t>(e[1])];
    }
    std::queue<int> q;
    for (int i = 0; i < n; ++i)
        if (deg[static_cast<size_t>(i)] == 1)
            q.push(i);
    int remain = n;
    while (remain > 2) {
        int sz = static_cast<int>(q.size());
        remain -= sz;
        for (int i = 0; i < sz; ++i) {
            int u = q.front();
            q.pop();
            for (int v : g[static_cast<size_t>(u)])
                if (--deg[static_cast<size_t>(v)] == 1)
                    q.push(v);
        }
    }
    std::vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}

int main() {
    auto a = findMinHeightTrees(4, {{1, 0}, {1, 2}, {1, 3}});
    std::cout << "mht:";
    for (int x : a)
        std::cout << " " << x;
    std::cout << " (expected 1)\n";
    auto b = findMinHeightTrees(6, {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}});
    std::cout << "mht:";
    for (int x : b)
        std::cout << " " << x;
    std::cout << " (expected 3 4)\n";
    return 0;
}
