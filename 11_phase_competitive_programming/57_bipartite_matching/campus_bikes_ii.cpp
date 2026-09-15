// Campus Bikes II — LeetCode 1066 (premium)
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int assignBikes(const std::vector<std::vector<int>>& workers,
                const std::vector<std::vector<int>>& bikes) {
    int n = static_cast<int>(workers.size()), m = static_cast<int>(bikes.size());
    std::vector<int> dp(1 << m, 1e9);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << m); ++mask) {
        int w = __builtin_popcount(static_cast<unsigned>(mask));
        if (w >= n)
            continue;
        for (int b = 0; b < m; ++b) {
            if (mask & (1 << b))
                continue;
            int dist =
                std::abs(workers[static_cast<size_t>(w)][0] - bikes[static_cast<size_t>(b)][0]) +
                std::abs(workers[static_cast<size_t>(w)][1] - bikes[static_cast<size_t>(b)][1]);
            int nmask = mask | (1 << b);
            dp[static_cast<size_t>(nmask)] =
                std::min(dp[static_cast<size_t>(nmask)], dp[static_cast<size_t>(mask)] + dist);
        }
    }
    int ans = 1e9;
    for (int mask = 0; mask < (1 << m); ++mask)
        if (__builtin_popcount(static_cast<unsigned>(mask)) == n)
            ans = std::min(ans, dp[static_cast<size_t>(mask)]);
    return ans;
}

int main() {
    std::cout << assignBikes({{0, 0}, {2, 1}}, {{1, 2}, {3, 3}}) << " (expected 6)\n";
    return 0;
}
