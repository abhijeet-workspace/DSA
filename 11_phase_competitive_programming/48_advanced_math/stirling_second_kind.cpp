#include <iostream>
#include <vector>
long long stirling2(int n, int k) {
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(k + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= std::min(i, k); ++j)
            dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
    return dp[n][k];
}
int main() {
    std::cout << stirling2(5, 2) << " (expected 15)\n";
}