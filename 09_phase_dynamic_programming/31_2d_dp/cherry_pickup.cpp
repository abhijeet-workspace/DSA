// Cherry Pickup — https://leetcode.com/problems/cherry-pickup/
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int cherryPickup(std::vector<std::vector<int>>& grid) {
    const int n = static_cast<int>(grid.size());
    std::vector<std::vector<std::vector<int>>> memo(
        n, std::vector<std::vector<int>>(n, std::vector<int>(n, -2)));
    std::function<int(int, int, int)> dfs = [&](int r1, int c1, int r2) -> int {
        const int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || c2 < 0 ||
            grid[static_cast<size_t>(r1)][static_cast<size_t>(c1)] < 0 ||
            grid[static_cast<size_t>(r2)][static_cast<size_t>(c2)] < 0) {
            return -1e9;
        }
        if (r1 == n - 1 && c1 == n - 1)
            return grid[static_cast<size_t>(r1)][static_cast<size_t>(c1)];
        int& res = memo[static_cast<size_t>(r1)][static_cast<size_t>(c1)][static_cast<size_t>(r2)];
        if (res != -2)
            return res;
        int cherries = grid[static_cast<size_t>(r1)][static_cast<size_t>(c1)];
        if (r1 != r2)
            cherries += grid[static_cast<size_t>(r2)][static_cast<size_t>(c2)];
        const int best = std::max({dfs(r1 + 1, c1, r2 + 1), dfs(r1, c1 + 1, r2),
                                   dfs(r1 + 1, c1, r2), dfs(r1, c1 + 1, r2 + 1)});
        res = cherries + best;
        return res;
    };
    return std::max(0, dfs(0, 0, 0));
}

int main() {
    std::vector<std::vector<int>> g{{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    std::cout << cherryPickup(g) << " (expected 5)\n";
    return 0;
}
