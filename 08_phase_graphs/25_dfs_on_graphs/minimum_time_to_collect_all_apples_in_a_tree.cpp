// Minimum Time to Collect All Apples in a Tree
// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
#include <iostream>
#include <vector>

int dfs(int u, int parent, const std::vector<std::vector<int>>& g, const std::vector<bool>& hasApple,
        int& time) {
    int apples = hasApple[static_cast<size_t>(u)] ? 1 : 0;
    for (int v : g[static_cast<size_t>(u)]) {
        if (v == parent) continue;
        int sub = dfs(v, u, g, hasApple, time);
        if (sub > 0) {
            time += 2; // go to child and back
            apples += sub;
        }
    }
    return apples;
}

int minTime(int n, const std::vector<std::vector<int>>& edges, const std::vector<bool>& hasApple) {
    std::vector<std::vector<int>> g(static_cast<size_t>(n));
    for (const auto& e : edges) {
        g[static_cast<size_t>(e[0])].push_back(e[1]);
        g[static_cast<size_t>(e[1])].push_back(e[0]);
    }
    int time = 0;
    dfs(0, -1, g, hasApple, time);
    return time;
}

int main() {
    std::cout << minTime(7, {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}},
                         {false, false, true, false, true, true, false})
              << " (expected 8)\n";
    return 0;
}
