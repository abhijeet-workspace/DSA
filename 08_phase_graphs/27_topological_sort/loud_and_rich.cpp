// Loud and Rich — https://leetcode.com/problems/loud-and-rich/
// richer[i]=[a,b] means a>b wealth. quiet[i] quieter number. For each x, poorest? answer:
// person with minimum quiet among those as rich or richer than x (including x).
#include <algorithm>
#include <iostream>
#include <vector>

int dfs(int u, const std::vector<std::vector<int>>& richerThan, const std::vector<int>& quiet,
        std::vector<int>& ans) {
    if (ans[static_cast<size_t>(u)] != -1) return ans[static_cast<size_t>(u)];
    ans[static_cast<size_t>(u)] = u;
    for (int v : richerThan[static_cast<size_t>(u)]) {
        int cand = dfs(v, richerThan, quiet, ans);
        if (quiet[static_cast<size_t>(cand)] < quiet[static_cast<size_t>(ans[static_cast<size_t>(u)])])
            ans[static_cast<size_t>(u)] = cand;
    }
    return ans[static_cast<size_t>(u)];
}

std::vector<int> loudAndRich(const std::vector<std::vector<int>>& richer, const std::vector<int>& quiet) {
    const int n = static_cast<int>(quiet.size());
    std::vector<std::vector<int>> richerThan(static_cast<size_t>(n)); // edge poor <- rich : rich points to? 
    // richer a,b => a richer than b: edge a→b means a is richer (topo from rich to poor)
    // For query on x we need people richer than x: edges into x from richer people.
    std::vector<std::vector<int>> richerPeople(static_cast<size_t>(n));
    for (const auto& e : richer) richerPeople[static_cast<size_t>(e[1])].push_back(e[0]);
    std::vector<int> ans(static_cast<size_t>(n), -1);
    for (int i = 0; i < n; ++i) dfs(i, richerPeople, quiet, ans);
    return ans;
}

int main() {
    const auto r = loudAndRich({{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}},
                               {3, 2, 5, 4, 6, 1, 7, 0});
    for (int x : r) std::cout << x << " ";
    std::cout << "\n"; // 5 5 2 5 4 5 6 7
    return 0;
}
