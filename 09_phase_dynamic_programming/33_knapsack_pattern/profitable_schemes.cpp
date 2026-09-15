// Profitable Schemes — https://leetcode.com/problems/profitable-schemes/
#include <algorithm>
#include <iostream>
#include <vector>

int profitableSchemes(int n, int minProfit, std::vector<int>& group, std::vector<int>& profit) {
    constexpr int MOD = 1'000'000'007;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(minProfit + 1, 0));
    dp[0][0] = 1;
    const int K = static_cast<int>(group.size());
    for (int k = 0; k < K; ++k) {
        const int g = group[static_cast<size_t>(k)];
        const int p = profit[static_cast<size_t>(k)];
        for (int j = n; j >= g; --j) {
            for (int q = minProfit; q >= 0; --q) {
                const int np = std::min(minProfit, q + p);
                dp[static_cast<size_t>(j)][static_cast<size_t>(np)] =
                    (dp[static_cast<size_t>(j)][static_cast<size_t>(np)] +
                     dp[static_cast<size_t>(j - g)][static_cast<size_t>(q)]) % MOD;
            }
        }
    }
    long long ans = 0;
    for (int j = 0; j <= n; ++j) ans = (ans + dp[static_cast<size_t>(j)][static_cast<size_t>(minProfit)]) % MOD;
    return static_cast<int>(ans);
}

int main() {
    std::vector<int> group{2, 2}, profit{2, 3};
    std::cout << profitableSchemes(5, 3, group, profit) << " (expected 2)\n";
    return 0;
}
