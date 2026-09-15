// Parallel Courses — LeetCode 1136 (premium)
// Minimum semesters with unlimited parallel courses; unit time each.
#include <iostream>
#include <queue>
#include <vector>

int minimumSemesters(int n, const std::vector<std::vector<int>>& relations) {
    std::vector<std::vector<int>> g(static_cast<size_t>(n) + 1);
    std::vector<int> indeg(static_cast<size_t>(n) + 1, 0);
    for (const auto& r : relations) {
        g[static_cast<size_t>(r[0])].push_back(r[1]);
        ++indeg[static_cast<size_t>(r[1])];
    }
    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indeg[static_cast<size_t>(i)] == 0)
            q.push(i);
    int sem = 0, taken = 0;
    while (!q.empty()) {
        int sz = static_cast<int>(q.size());
        ++sem;
        for (int i = 0; i < sz; ++i) {
            int u = q.front();
            q.pop();
            ++taken;
            for (int v : g[static_cast<size_t>(u)])
                if (--indeg[static_cast<size_t>(v)] == 0)
                    q.push(v);
        }
    }
    return taken == n ? sem : -1;
}

int main() {
    std::cout << minimumSemesters(3, {{1, 3}, {2, 3}}) << " (expected 2)\n";
    std::cout << minimumSemesters(3, {{1, 2}, {2, 3}, {3, 1}}) << " (expected -1)\n";
    return 0;
}
