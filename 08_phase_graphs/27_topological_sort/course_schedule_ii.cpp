// Course Schedule II — https://leetcode.com/problems/course-schedule-ii/
// Return any valid course order, or empty if a cycle exists.
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> findOrder(int numCourses,
                           const std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> g(static_cast<size_t>(numCourses));
    std::vector<int> indeg(static_cast<size_t>(numCourses), 0);
    for (const auto& e : prerequisites) {
        g[static_cast<size_t>(e[1])].push_back(e[0]); // b before a
        ++indeg[static_cast<size_t>(e[0])];
    }
    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (indeg[static_cast<size_t>(i)] == 0) {
            q.push(i);
        }
    }
    std::vector<int> order;
    while (!q.empty()) {
        const int u = q.front();
        q.pop();
        order.push_back(u); // record Kahn pop order
        for (int v : g[static_cast<size_t>(u)]) {
            if (--indeg[static_cast<size_t>(v)] == 0) {
                q.push(v);
            }
        }
    }
    return static_cast<int>(order.size()) == numCourses ? order : std::vector<int>{};
}

int main() {
    const auto o = findOrder(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}});
    std::cout << "order:";
    for (int x : o) {
        std::cout << " " << x;
    }
    std::cout << " (size expected 4)\n";
    return 0;
}
