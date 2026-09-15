// Number of Ways to Wear Different Hats to Each Other —
// https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
#include <iostream>
#include <vector>

int numberWays(std::vector<std::vector<int>>& hats) {
    constexpr int MOD = 1'000'000'007;
    const int n = static_cast<int>(hats.size());
    std::vector<std::vector<int>> hatToPeople(41);
    for (int p = 0; p < n; ++p)
        for (int h : hats[static_cast<size_t>(p)])
            hatToPeople[static_cast<size_t>(h)].push_back(p);
    const int N = 1 << n;
    std::vector<int> dp(N, 0);
    dp[0] = 1;
    for (int h = 1; h <= 40; ++h) {
        for (int mask = N - 1; mask >= 0; --mask) {
            for (int p : hatToPeople[static_cast<size_t>(h)]) {
                if (mask & (1 << p))
                    continue;
                dp[static_cast<size_t>(mask | (1 << p))] =
                    (dp[static_cast<size_t>(mask | (1 << p))] + dp[static_cast<size_t>(mask)]) %
                    MOD;
            }
        }
    }
    return dp[static_cast<size_t>(N - 1)];
}

int main() {
    std::vector<std::vector<int>> hats{{3, 4}, {4, 5}, {5}};
    std::cout << numberWays(hats) << " (expected 1)\n";
    return 0;
}
