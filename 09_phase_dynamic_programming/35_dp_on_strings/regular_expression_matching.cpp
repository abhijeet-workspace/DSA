// Regular Expression Matching — https://leetcode.com/problems/regular-expression-matching/
// Match entire string with pattern supporting '.' and '*' (DP).
#include <iostream>
#include <string>
#include <vector>

bool isMatch(const std::string& s, const std::string& p) {
    const int m = static_cast<int>(s.size());
    const int n = static_cast<int>(p.size());
    std::vector<std::vector<bool>> dp(static_cast<size_t>(m + 1),
                                      std::vector<bool>(static_cast<size_t>(n + 1), false));
    dp[0][0] = true;
    for (int j = 2; j <= n; ++j) {
        if (p[static_cast<size_t>(j - 1)] == '*') {
            dp[0][static_cast<size_t>(j)] = dp[0][static_cast<size_t>(j - 2)];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[static_cast<size_t>(j - 1)] == '*') {
                dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    dp[static_cast<size_t>(i)][static_cast<size_t>(j - 2)];
                if (p[static_cast<size_t>(j - 2)] == '.' ||
                    p[static_cast<size_t>(j - 2)] == s[static_cast<size_t>(i - 1)]) {
                    dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                        dp[static_cast<size_t>(i)][static_cast<size_t>(j)] ||
                        dp[static_cast<size_t>(i - 1)][static_cast<size_t>(j)];
                }
            } else if (p[static_cast<size_t>(j - 1)] == '.' ||
                       p[static_cast<size_t>(j - 1)] == s[static_cast<size_t>(i - 1)]) {
                dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    dp[static_cast<size_t>(i - 1)][static_cast<size_t>(j - 1)];
            }
        }
    }
    return dp[static_cast<size_t>(m)][static_cast<size_t>(n)];
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isMatch("aa", "a") << " (expected false)\n";
    std::cout << isMatch("aa", "a*") << " (expected true)\n";
    std::cout << isMatch("ab", ".*") << " (expected true)\n";
    std::cout << isMatch("aab", "c*a*b") << " (expected true)\n";
    return 0;
}
