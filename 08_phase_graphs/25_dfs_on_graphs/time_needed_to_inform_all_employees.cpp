// Time Needed to Inform All Employees — https://leetcode.com/problems/time-needed-to-inform-all-employees/
#include <algorithm>
#include <iostream>
#include <vector>

int dfs(int u, const std::vector<std::vector<int>>& children, const std::vector<int>& informTime) {
    int best = 0;
    for (int v : children[static_cast<size_t>(u)]) {
        best = std::max(best, dfs(v, children, informTime));
    }
    return informTime[static_cast<size_t>(u)] + best;
}

int numOfMinutes(int n, int headID, const std::vector<int>& manager, const std::vector<int>& informTime) {
    std::vector<std::vector<int>> children(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        if (manager[static_cast<size_t>(i)] != -1)
            children[static_cast<size_t>(manager[static_cast<size_t>(i)])].push_back(i);
    }
    return dfs(headID, children, informTime);
}

int main() {
    std::cout << numOfMinutes(6, 2, {2, 2, -1, 2, 2, 2}, {0, 0, 1, 0, 0, 0}) << " (expected 1)\n";
    return 0;
}
