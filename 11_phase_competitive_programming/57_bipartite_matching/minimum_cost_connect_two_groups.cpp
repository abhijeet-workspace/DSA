// Minimum Cost to Connect Two Groups of Points — LeetCode 1595
#include <algorithm>
#include <iostream>
#include <vector>

int connectTwoGroups(const std::vector<std::vector<int>>& cost) {
    int n = static_cast<int>(cost.size()), m = static_cast<int>(cost[0].size());
    std::vector<int> minRight(static_cast<size_t>(m), 1e9);
    for (int j = 0; j < m; ++j)
        for (int i = 0; i < n; ++i)
            minRight[static_cast<size_t>(j)] =
                std::min(minRight[static_cast<size_t>(j)],
                         cost[static_cast<size_t>(i)][static_cast<size_t>(j)]);
    int M = 1 << m;
    std::vector<int> dp(static_cast<size_t>(M), 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        std::vector<int> ndp(static_cast<size_t>(M), 1e9);
        for (int mask = 0; mask < M; ++mask) {
            if (dp[static_cast<size_t>(mask)] >= 1e9)
                continue;
            for (int j = 0; j < m; ++j) {
                int nmask = mask | (1 << j);
                ndp[static_cast<size_t>(nmask)] =
                    std::min(ndp[static_cast<size_t>(nmask)],
                             dp[static_cast<size_t>(mask)] +
                                 cost[static_cast<size_t>(i)][static_cast<size_t>(j)]);
            }
        }
        dp.swap(ndp);
    }
    int ans = 1e9;
    for (int mask = 0; mask < M; ++mask) {
        int extra = 0;
        for (int j = 0; j < m; ++j)
            if (((mask >> j) & 1) == 0)
                extra += minRight[static_cast<size_t>(j)];
        ans = std::min(ans, dp[static_cast<size_t>(mask)] + extra);
    }
    return ans;
}

int main() {
    std::cout << connectTwoGroups({{1, 3, 5}, {4, 1, 1}, {1, 5, 3}}) << " (expected 4)\n";
    return 0;
}
