// Count Different Palindromic Subsequences — https://leetcode.com/problems/count-different-palindromic-subsequences/
#include <iostream>
#include <string>
#include <vector>

int countPalindromicSubsequences(std::string s) {
    constexpr int MOD = 1'000'000'007;
    const int n = static_cast<int>(s.size());
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) dp[static_cast<size_t>(i)][static_cast<size_t>(i)] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            const int j = i + len - 1;
            if (s[static_cast<size_t>(i)] != s[static_cast<size_t>(j)]) {
                dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    (dp[static_cast<size_t>(i + 1)][static_cast<size_t>(j)] +
                     dp[static_cast<size_t>(i)][static_cast<size_t>(j - 1)] -
                     dp[static_cast<size_t>(i + 1)][static_cast<size_t>(j - 1)]) % MOD;
                if (dp[static_cast<size_t>(i)][static_cast<size_t>(j)] < 0)
                    dp[static_cast<size_t>(i)][static_cast<size_t>(j)] += MOD;
            } else {
                int l = i + 1, r = j - 1;
                while (l <= r && s[static_cast<size_t>(l)] != s[static_cast<size_t>(i)]) ++l;
                while (l <= r && s[static_cast<size_t>(r)] != s[static_cast<size_t>(i)]) --r;
                if (l > r) {
                    dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                        (2 * dp[static_cast<size_t>(i + 1)][static_cast<size_t>(j - 1)] + 2) % MOD;
                } else if (l == r) {
                    dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                        (2 * dp[static_cast<size_t>(i + 1)][static_cast<size_t>(j - 1)] + 1) % MOD;
                } else {
                    dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                        (2 * dp[static_cast<size_t>(i + 1)][static_cast<size_t>(j - 1)] -
                         dp[static_cast<size_t>(l + 1)][static_cast<size_t>(r - 1)]) % MOD;
                    if (dp[static_cast<size_t>(i)][static_cast<size_t>(j)] < 0)
                        dp[static_cast<size_t>(i)][static_cast<size_t>(j)] += MOD;
                }
            }
        }
    }
    return dp[0][static_cast<size_t>(n - 1)];
}

int main() {
    std::cout << countPalindromicSubsequences("bccb") << " (expected 6)\n";
    return 0;
}
