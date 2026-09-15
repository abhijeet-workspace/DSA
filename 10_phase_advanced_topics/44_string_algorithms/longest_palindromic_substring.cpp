// Longest Palindromic Substring — https://leetcode.com/problems/longest-palindromic-substring/
// Expand around odd/even centers; track best window.
#include <iostream>
#include <string>

std::string longestPalindrome(const std::string& s) {
    int n = static_cast<int>(s.size());
    int bestL = 0, bestR = 0;
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
        }
        ++l;
        --r;
        if (r - l > bestR - bestL) {
            bestL = l;
            bestR = r;
        }
    };
    for (int i = 0; i < n; ++i) {
        expand(i, i);
        expand(i, i + 1);
    }
    return s.substr(bestL, bestR - bestL + 1);
}

int main() {
    std::cout << longestPalindrome("babad") << " (expected bab or aba)\n"
              << longestPalindrome("cbbd") << " (expected bb)\n";
    return 0;
}
