// Shortest Palindrome — https://leetcode.com/problems/shortest-palindrome/
// LPS of s + '#' + reverse(s) = longest palindromic prefix length.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string shortestPalindrome(std::string s) {
    std::string rev = s;
    std::reverse(rev.begin(), rev.end());
    std::string t = s + "#" + rev;
    int m = static_cast<int>(t.size());
    std::vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m;) {
        if (t[i] == t[len])
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    int pref = lps.back();
    return rev.substr(0, s.size() - pref) + s;
}

int main() {
    std::cout << shortestPalindrome("aacecaaa") << " (expected aaacecaaa)\n"
              << shortestPalindrome("abcd") << " (expected dcbabcd)\n";
    return 0;
}
