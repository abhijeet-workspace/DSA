#include <iostream>
int checkRecord(int n) {
    constexpr int MOD = 1'000'000'007;
    long long dp[2][3] = {{1, 0, 0}, {0, 0, 0}};
    for (int i = 0; i < n; ++i) {
        long long ndp[2][3] = {};
        for (int a = 0; a < 2; ++a)
            for (int l = 0; l < 3; ++l) {
                long long v = dp[a][l];
                if (!v)
                    continue;
                ndp[a][0] = (ndp[a][0] + v) % MOD;
                if (a + 1 < 2)
                    ndp[a + 1][0] = (ndp[a + 1][0] + v) % MOD;
                if (l + 1 < 3)
                    ndp[a][l + 1] = (ndp[a][l + 1] + v) % MOD;
            }
        for (int a = 0; a < 2; ++a)
            for (int l = 0; l < 3; ++l)
                dp[a][l] = ndp[a][l];
    }
    long long ans = 0;
    for (int a = 0; a < 2; ++a)
        for (int l = 0; l < 3; ++l)
            ans += dp[a][l];
    return (int)(ans % MOD);
}
int main() {
    std::cout << "r(1)=" << checkRecord(1) << " (expected 3)\nr(2)=" << checkRecord(2)
              << " (expected 8)\n";
    return 0;
}
