// Course Schedule IV — LeetCode 1462
// Reachability DP / Floyd on prereq DAG.
#include <iostream>
#include <vector>

std::vector<bool> checkIfPrerequisite(int numCourses,
                                      const std::vector<std::vector<int>>& prerequisites,
                                      const std::vector<std::vector<int>>& queries) {
    std::vector<std::vector<char>> reach(static_cast<size_t>(numCourses),
                                         std::vector<char>(static_cast<size_t>(numCourses), 0));
    for (const auto& e : prerequisites)
        reach[static_cast<size_t>(e[0])][static_cast<size_t>(e[1])] = 1;
    for (int k = 0; k < numCourses; ++k)
        for (int i = 0; i < numCourses; ++i)
            if (reach[static_cast<size_t>(i)][static_cast<size_t>(k)])
                for (int j = 0; j < numCourses; ++j)
                    if (reach[static_cast<size_t>(k)][static_cast<size_t>(j)])
                        reach[static_cast<size_t>(i)][static_cast<size_t>(j)] = 1;
    std::vector<bool> ans;
    for (const auto& q : queries)
        ans.push_back(reach[static_cast<size_t>(q[0])][static_cast<size_t>(q[1])]);
    return ans;
}

int main() {
    auto a = checkIfPrerequisite(3, {{1, 2}, {1, 0}, {2, 0}}, {{1, 0}, {1, 2}});
    std::cout << a[0] << " " << a[1] << " (expected 1 1)\n";
    return 0;
}
