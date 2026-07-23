// Longest Common Subsequence — https://leetcode.com/problems/longest-common-subsequence/
// Length of the longest subsequence common to text1 and text2.
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int longestCommonSubsequence(std::string text1, std::string text2) {
    if (text1.size() < text2.size()) {
        std::swap(text1, text2); // keep text2 shorter for space
    }
    const int m = static_cast<int>(text1.size());
    const int n = static_cast<int>(text2.size());
    std::vector<int> prev(static_cast<size_t>(n) + 1, 0);
    std::vector<int> curr(static_cast<size_t>(n) + 1, 0);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[static_cast<size_t>(i - 1)] == text2[static_cast<size_t>(j - 1)]) {
                curr[static_cast<size_t>(j)] = 1 + prev[static_cast<size_t>(j - 1)]; // match
            } else {
                curr[static_cast<size_t>(j)] = std::max(prev[static_cast<size_t>(j)],
                                                        curr[static_cast<size_t>(j - 1)]);
            }
        }
        prev.swap(curr);
        std::fill(curr.begin(), curr.end(), 0); // reset next row
    }
    return prev[static_cast<size_t>(n)];
}

int main() {
    std::cout << longestCommonSubsequence("abcde", "ace") << " (expected 3)\n"
              << longestCommonSubsequence("abc", "abc") << " (expected 3)\n"
              << longestCommonSubsequence("abc", "def") << " (expected 0)\n";
    return 0;
}
