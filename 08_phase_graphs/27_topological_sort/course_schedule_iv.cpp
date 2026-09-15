// Course Schedule IV — https://leetcode.com/problems/course-schedule-iv/
// For each query [u,v], is there a path u → ... → v in the prereq graph?
#include <iostream>
#include <vector>

void dfs(int src, int u, const std::vector<std::vector<int>>& g,
         std::vector<std::vector<bool>>& reach) {
    for (int v : g[static_cast<size_t>(u)]) {
        if (!reach[static_cast<size_t>(src)][static_cast<size_t>(v)]) {
            reach[static_cast<size_t>(src)][static_cast<size_t>(v)] = true;
            dfs(src, v, g, reach);
        }
    }
}

std::vector<bool> checkIfPrerequisite(int numCourses,
                                      const std::vector<std::vector<int>>& prerequisites,
                                      const std::vector<std::vector<int>>& queries) {
    std::vector<std::vector<int>> g(static_cast<size_t>(numCourses));
    for (const auto& e : prerequisites) {
        g[static_cast<size_t>(e[0])].push_back(e[1]); // a is prereq of b → a→b
    }
    std::vector<std::vector<bool>> reach(static_cast<size_t>(numCourses),
                                         std::vector<bool>(static_cast<size_t>(numCourses), false));
    for (int i = 0; i < numCourses; ++i) {
        dfs(i, i, g, reach);
    }
    std::vector<bool> ans;
    ans.reserve(queries.size());
    for (const auto& q : queries) {
        ans.push_back(reach[static_cast<size_t>(q[0])][static_cast<size_t>(q[1])]);
    }
    return ans;
}

int main() {
    const auto ans = checkIfPrerequisite(3, {{1, 2}, {1, 0}, {2, 0}}, {{1, 0}, {1, 2}});
    std::cout << std::boolalpha << ans[0] << " " << ans[1] << " (expected true true)\n";
    return 0;
}
