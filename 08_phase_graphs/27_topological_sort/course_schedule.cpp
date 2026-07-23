// Course Schedule — https://leetcode.com/problems/course-schedule/
// True iff all courses can be finished (prereq graph is a DAG).
#include <iostream>
#include <queue>
#include <vector>

bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> g(static_cast<size_t>(numCourses));
    std::vector<int> indeg(static_cast<size_t>(numCourses), 0);
    for (const auto& e : prerequisites) {
        const int a = e[0];
        const int b = e[1];
        g[static_cast<size_t>(b)].push_back(a); // b before a
        ++indeg[static_cast<size_t>(a)];
    }
    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (indeg[static_cast<size_t>(i)] == 0) {
            q.push(i);
        }
    }
    int taken = 0;
    while (!q.empty()) {
        const int u = q.front();
        q.pop();
        ++taken;
        for (int v : g[static_cast<size_t>(u)]) {
            if (--indeg[static_cast<size_t>(v)] == 0) {
                q.push(v);
            }
        }
    }
    return taken == numCourses; // unfinished → cycle
}

int main() {
    std::cout << std::boolalpha
              << canFinish(2, {{1, 0}}) << " (expected true)\n"
              << canFinish(2, {{1, 0}, {0, 1}}) << " (expected false)\n";
    return 0;
}
