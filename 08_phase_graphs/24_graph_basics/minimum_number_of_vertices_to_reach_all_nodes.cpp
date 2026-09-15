// Minimum Number of Vertices to Reach All Nodes
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
#include <iostream>
#include <vector>

std::vector<int> findSmallestSetOfVertices(int n, const std::vector<std::vector<int>>& edges) {
    std::vector<char> hasIn(static_cast<size_t>(n), 0);
    for (const auto& e : edges)
        hasIn[static_cast<size_t>(e[1])] = 1;
    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (!hasIn[static_cast<size_t>(i)])
            ans.push_back(i);
    }
    return ans;
}

int main() {
    const auto r = findSmallestSetOfVertices(6, {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}});
    std::cout << "count=" << r.size() << " (expected 2)\n";
    for (int x : r)
        std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
