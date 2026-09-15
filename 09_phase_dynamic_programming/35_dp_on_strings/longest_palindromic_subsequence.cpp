// Longest Palindromic Subsequence — https://leetcode.com/problems/longest-palindromic-subsequence/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longestPalindromeSubseq(std::string s) {
    const int n = static_cast<int>(s.size());
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for (int i = n - 1; i >= 0; --i) {
        dp[static_cast<size_t>(i)][static_cast<size_t>(i)] = 1;
        for (int j = i + 1; j < n; ++j) {
            if (s[static_cast<size_t>(i)] == s[static_cast<size_t>(j)]) {
                dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    2 + dp[static_cast<size_t>(i + 1)][static_cast<size_t>(j - 1)];
            } else {
                dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    std::max(dp[static_cast<size_t>(i + 1)][static_cast<size_t>(j)],
                             dp[static_cast<size_t>(i)][static_cast<size_t>(j - 1)]);
            }
        }
    }
    return dp[0][static_cast<size_t>(n - 1)];
}

int main() {
    std::cout << longestPalindromeSubseq("bbbab") << " (expected 4)\n";
    return 0;
}
