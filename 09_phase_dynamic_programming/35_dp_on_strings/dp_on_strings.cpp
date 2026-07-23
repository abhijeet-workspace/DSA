// DP on Strings — Distinct Subsequences (115), Wildcard Matching (44).
// 1D rolling for counts; 2D bool table for wildcard.
#include <iostream>
#include <string>
#include <vector>

int numDistinct(const std::string& s, const std::string& t) {
    const int m = static_cast<int>(s.size());
    const int n = static_cast<int>(t.size());
    if (m < n) {
        return 0;
    }
    std::vector<unsigned long long> dp(static_cast<size_t>(n) + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >= 1; --j) {
            if (s[static_cast<size_t>(i - 1)] == t[static_cast<size_t>(j - 1)]) {
                dp[static_cast<size_t>(j)] += dp[static_cast<size_t>(j - 1)];
            }
        }
    }
    return static_cast<int>(dp[static_cast<size_t>(n)]);
}

bool isMatch(const std::string& s, const std::string& p) {
    const int m = static_cast<int>(s.size());
    const int n = static_cast<int>(p.size());
    std::vector<std::vector<bool>> dp(static_cast<size_t>(m) + 1,
                                      std::vector<bool>(static_cast<size_t>(n) + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= n; ++j) {
        if (p[static_cast<size_t>(j - 1)] == '*') {
            dp[0][static_cast<size_t>(j)] = dp[0][static_cast<size_t>(j - 1)];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            const char pc = p[static_cast<size_t>(j - 1)];
            if (pc == '?' || pc == s[static_cast<size_t>(i - 1)]) {
                dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    dp[static_cast<size_t>(i - 1)][static_cast<size_t>(j - 1)];
            } else if (pc == '*') {
                dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    dp[static_cast<size_t>(i - 1)][static_cast<size_t>(j)] ||
                    dp[static_cast<size_t>(i)][static_cast<size_t>(j - 1)];
            }
        }
    }
    return dp[static_cast<size_t>(m)][static_cast<size_t>(n)];
}

int main() {
    std::cout << numDistinct("rabbbit", "rabbit") << " (expected 3)\n";
    std::cout << std::boolalpha << isMatch("adceb", "*a*b") << " (expected true)\n";
    return 0;
}
