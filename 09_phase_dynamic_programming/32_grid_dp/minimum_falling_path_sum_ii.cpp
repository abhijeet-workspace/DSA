// Minimum Falling Path Sum II — https://leetcode.com/problems/minimum-falling-path-sum-ii/
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int minFallingPathSum(std::vector<std::vector<int>>& grid) {
    const int n = static_cast<int>(grid.size());
    std::vector<int> dp = grid[0];
    for (int r = 1; r < n; ++r) {
        int m1 = std::numeric_limits<int>::max(), m2 = m1, i1 = -1;
        for (int c = 0; c < n; ++c) {
            if (dp[static_cast<size_t>(c)] < m1) {
                m2 = m1;
                m1 = dp[static_cast<size_t>(c)];
                i1 = c;
            } else if (dp[static_cast<size_t>(c)] < m2) {
                m2 = dp[static_cast<size_t>(c)];
            }
        }
        std::vector<int> ndp(n);
        for (int c = 0; c < n; ++c) {
            ndp[static_cast<size_t>(c)] =
                grid[static_cast<size_t>(r)][static_cast<size_t>(c)] + (c == i1 ? m2 : m1);
        }
        dp.swap(ndp);
    }
    return *std::min_element(dp.begin(), dp.end());
}

int main() {
    std::vector<std::vector<int>> g{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << minFallingPathSum(g) << " (expected 13)\n";
    return 0;
}
