// Longest Palindromic Substring — https://leetcode.com/problems/longest-palindromic-substring/
#include <iostream>
#include <string>

std::string longestPalindrome(std::string s) {
    const int n = static_cast<int>(s.size());
    if (n == 0)
        return "";
    int bestL = 0, bestLen = 1;
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[static_cast<size_t>(l)] == s[static_cast<size_t>(r)]) {
            --l;
            ++r;
        }
        const int len = r - l - 1;
        if (len > bestLen) {
            bestLen = len;
            bestL = l + 1;
        }
    };
    for (int i = 0; i < n; ++i) {
        expand(i, i);
        expand(i, i + 1);
    }
    return s.substr(static_cast<size_t>(bestL), static_cast<size_t>(bestLen));
}

int main() {
    std::cout << longestPalindrome("babad") << " (expected bab or aba)\n";
    return 0;
}
