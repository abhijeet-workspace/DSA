// Interleaving String — https://leetcode.com/problems/interleaving-string/
// True if s3 is formed by interleaving s1 and s2 preserving order.
#include <iostream>
#include <string>
#include <vector>

bool isInterleave(std::string s1, std::string s2, std::string s3) {
    const int m = static_cast<int>(s1.size());
    const int n = static_cast<int>(s2.size());
    if (m + n != static_cast<int>(s3.size())) {
        return false; // length must match
    }
    std::vector<char> dp(n + 1, 0); // dp[j]: s1[:i] + s2[:j] forms s3[:i+j]
    dp[0] = 1;
    for (int j = 1; j <= n; ++j) {
        dp[j] = dp[j - 1] && s2[static_cast<size_t>(j - 1)] == s3[static_cast<size_t>(j - 1)];
    }
    for (int i = 1; i <= m; ++i) {
        dp[0] = dp[0] && s1[static_cast<size_t>(i - 1)] == s3[static_cast<size_t>(i - 1)];
        for (int j = 1; j <= n; ++j) {
            const bool from_s1 = dp[j] && s1[static_cast<size_t>(i - 1)] == s3[static_cast<size_t>(i + j - 1)];
            const bool from_s2 = dp[j - 1] && s2[static_cast<size_t>(j - 1)] == s3[static_cast<size_t>(i + j - 1)];
            dp[j] = from_s1 || from_s2;
        }
    }
    return dp[n];
}

int main() {
    std::cout << std::boolalpha
              << isInterleave("aab", "axy", "aaxaby") << " (expected true)\n";
    return 0;
}
