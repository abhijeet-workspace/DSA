// Longest Palindromic Subsequence — https://leetcode.com/problems/longest-palindromic-subsequence/
// Length of the longest palindromic subsequence in s.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
    const int n = static_cast<int>(text1.size());
    std::vector<int> prev(n + 1, 0);
    std::vector<int> curr(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[static_cast<size_t>(i - 1)] == text2[static_cast<size_t>(j - 1)]) {
                curr[static_cast<size_t>(j)] = 1 + prev[static_cast<size_t>(j - 1)];
            } else {
                curr[static_cast<size_t>(j)] = std::max(prev[static_cast<size_t>(j)],
                                                        curr[static_cast<size_t>(j - 1)]);
            }
        }
        prev = curr; // roll to next row
    }
    return prev[static_cast<size_t>(n)];
}

int longestPalindromeSubseq(std::string s) {
    std::string rev = s;
    std::reverse(rev.begin(), rev.end()); // palindrome ↔ LCS(s, reverse(s))
    return longestCommonSubsequence(s, rev);
}

int main() {
    std::cout << longestPalindromeSubseq("bbbab") << " (expected 4)\n";
    return 0;
}
