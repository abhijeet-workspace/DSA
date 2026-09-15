// Cherry Pickup II — https://leetcode.com/problems/cherry-pickup-ii/
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int cherryPickup(std::vector<std::vector<int>>& grid) {
    const int R = static_cast<int>(grid.size());
    const int C = static_cast<int>(grid[0].size());
    std::vector<std::vector<std::vector<int>>> memo(
        R, std::vector<std::vector<int>>(C, std::vector<int>(C, -1)));
    std::function<int(int, int, int)> dfs = [&](int r, int c1, int c2) -> int {
        if (c1 < 0 || c2 < 0 || c1 >= C || c2 >= C) return -1e9;
        if (r == R - 1) {
            return grid[static_cast<size_t>(r)][static_cast<size_t>(c1)] +
                   (c1 == c2 ? 0 : grid[static_cast<size_t>(r)][static_cast<size_t>(c2)]);
        }
        int& res = memo[static_cast<size_t>(r)][static_cast<size_t>(c1)][static_cast<size_t>(c2)];
        if (res != -1) return res;
        int best = -1e9;
        for (int d1 = -1; d1 <= 1; ++d1)
            for (int d2 = -1; d2 <= 1; ++d2)
                best = std::max(best, dfs(r + 1, c1 + d1, c2 + d2));
        const int cur = grid[static_cast<size_t>(r)][static_cast<size_t>(c1)] +
                        (c1 == c2 ? 0 : grid[static_cast<size_t>(r)][static_cast<size_t>(c2)]);
        return res = cur + best;
    };
    return dfs(0, 0, C - 1);
}

int main() {
    std::vector<std::vector<int>> g{{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    std::cout << cherryPickup(g) << " (expected 24)\n";
    return 0;
}
