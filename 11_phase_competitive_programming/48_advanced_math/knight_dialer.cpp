#include <iostream>
#include <vector>
int knightDialer(int n) {
    constexpr int MOD = 1'000'000'007;
    std::vector<std::vector<int>> moves = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                                           {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    std::vector<int> dp(10, 1);
    for (int s = 1; s < n; ++s) {
        std::vector<int> ndp(10);
        for (int d = 0; d < 10; ++d)
            for (int m : moves[d])
                ndp[m] = (ndp[m] + dp[d]) % MOD;
        dp.swap(ndp);
    }
    long long ans = 0;
    for (int x : dp)
        ans += x;
    return (int)(ans % MOD);
}
int main() {
    std::cout << "k(1)=" << knightDialer(1) << " (expected 10)\nk(2)=" << knightDialer(2)
              << " (expected 20)\n";
    return 0;
}
