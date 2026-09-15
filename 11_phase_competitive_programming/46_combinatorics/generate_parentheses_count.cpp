// Count valid parentheses — Catalan
#include <iostream>
#include <vector>
int countParentheses(int n) {
    std::vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            dp[i] += dp[j] * dp[i - 1 - j];
    return (int)dp[n];
}
int main() {
    std::cout << countParentheses(3) << " (expected 5)\n";
    return 0;
}
