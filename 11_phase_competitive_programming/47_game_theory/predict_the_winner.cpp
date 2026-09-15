#include <algorithm>
#include <iostream>
#include <vector>
bool PredictTheWinner(const std::vector<int>& a) {
    int n = a.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        dp[i][i] = a[i];
    for (int len = 2; len <= n; ++len)
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp[i][j] = std::max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    return dp[0][n - 1] >= 0;
}
int main() {
    std::cout << std::boolalpha << "P([1,5,2])=" << PredictTheWinner({1, 5, 2})
              << " (expected false)\n"
              << "P([1,5,233,7])=" << PredictTheWinner({1, 5, 233, 7}) << " (expected true)\n";
    return 0;
}
