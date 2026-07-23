// Longest Palindromic Substring — https://leetcode.com/problems/longest-palindromic-substring/
// Return the longest palindromic substring of s (any one if ties).
#include <iostream>
#include <string>

std::string longestPalindrome(const std::string& s) {
    if (s.empty()) return "";
    int start = 0;
    int best = 1; // length of best palindrome
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < static_cast<int>(s.size()) && s[static_cast<size_t>(l)] == s[static_cast<size_t>(r)]) {
            --l; // grow left
            ++r; // grow right
        }
        const int len = r - l - 1; // exited one step past palindrome
        if (len > best) {
            best = len;
            start = l + 1;
        }
    };
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        expand(i, i); // odd center
        expand(i, i + 1); // even center
    }
    return s.substr(static_cast<size_t>(start), static_cast<size_t>(best));
}

int main() {
    std::cout << longestPalindrome("babad") << " (expected bab or aba)\n"
              << longestPalindrome("cbbd") << " (expected bb)\n";
    return 0;
}
