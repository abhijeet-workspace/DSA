// Out of Boundary Paths — https://leetcode.com/problems/out-of-boundary-paths/
#include <iostream>
#include <vector>

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    constexpr int MOD = 1'000'000'007;
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    dp[static_cast<size_t>(startRow)][static_cast<size_t>(startColumn)] = 1;
    long long ans = 0;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int move = 0; move < maxMove; ++move) {
        std::vector<std::vector<int>> ndp(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[static_cast<size_t>(i)][static_cast<size_t>(j)] == 0)
                    continue;
                for (auto& d : dirs) {
                    const int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
                        ans = (ans + dp[static_cast<size_t>(i)][static_cast<size_t>(j)]) % MOD;
                    } else {
                        ndp[static_cast<size_t>(ni)][static_cast<size_t>(nj)] =
                            (ndp[static_cast<size_t>(ni)][static_cast<size_t>(nj)] +
                             dp[static_cast<size_t>(i)][static_cast<size_t>(j)]) %
                            MOD;
                    }
                }
            }
        }
        dp.swap(ndp);
    }
    return static_cast<int>(ans);
}

int main() {
    std::cout << findPaths(1, 1, 1, 0, 0) << " (expected 4)\n";
    std::cout << findPaths(2, 2, 2, 0, 0) << " (expected 6)\n";
    return 0;
}
