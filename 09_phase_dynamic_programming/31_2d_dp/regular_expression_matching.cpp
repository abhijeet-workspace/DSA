// Regular Expression Matching — https://leetcode.com/problems/regular-expression-matching/
// Match entire s against pattern p with '.' and '*'.
#include <iostream>
#include <string>
#include <vector>

bool isMatch(std::string s, std::string p) {
    const int m = static_cast<int>(s.size());
    const int n = static_cast<int>(p.size());
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
    dp[0][0] = true; // empty matches empty
    for (int j = 2; j <= n; ++j) {
        if (p[static_cast<size_t>(j - 1)] == '*') {
            dp[0][j] = dp[0][j - 2]; // '*' takes zero of previous token
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[static_cast<size_t>(j - 1)] == '.' ||
                p[static_cast<size_t>(j - 1)] == s[static_cast<size_t>(i - 1)]) {
                dp[i][j] = dp[i - 1][j - 1]; // single-char match
            } else if (p[static_cast<size_t>(j - 1)] == '*') {
                dp[i][j] = dp[i][j - 2]; // zero occurrences of p[j-2]
                if (p[static_cast<size_t>(j - 2)] == '.' ||
                    p[static_cast<size_t>(j - 2)] == s[static_cast<size_t>(i - 1)]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j]; // one+ occurrences
                }
            }
        }
    }
    return dp[m][n];
}

int main() {
    std::cout << std::boolalpha
              << isMatch("aa", "a*") << " (expected true)\n";
    return 0;
}
