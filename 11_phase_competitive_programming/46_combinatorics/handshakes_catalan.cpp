// Handshakes That Don't Cross — LC 1259
#include <iostream>
#include <vector>
const int MOD = 1000000007;
int numberOfWays(int numPeople) {
    int n = numPeople / 2;
    std::vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            dp[i] = (dp[i] + dp[j] * dp[i - 1 - j]) % MOD;
    return (int)dp[n];
}
int main() {
    std::cout << numberOfWays(2) << " (expected 1)\n";
    std::cout << numberOfWays(4) << " (expected 2)\n";
    std::cout << numberOfWays(6) << " (expected 5)\n";
    return 0;
}
