// Manacher — longest palindromic substring in O(N)
// Transform with '#'; reuse mirror radii inside rightmost palindrome [C,R]
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string longestPalindrome(const std::string& s) {
    if (s.empty()) return "";
    std::string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }
    int n = static_cast<int>(t.size());
    std::vector<int> P(n, 0);
    int C = 0, R = 0;
    for (int i = 0; i < n; ++i) {
        int mirror = 2 * C - i;
        if (i < R) P[i] = std::min(R - i, P[mirror]);
        while (i - P[i] - 1 >= 0 && i + P[i] + 1 < n &&
               t[i - P[i] - 1] == t[i + P[i] + 1])
            ++P[i];
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    int maxLen = 0, centerIdx = 0;
    for (int i = 0; i < n; ++i) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIdx = i;
        }
    }
    int start = (centerIdx - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    std::cout << longestPalindrome("babad") << " (expected bab or aba)\n";
    std::cout << longestPalindrome("cbbd") << " (expected bb)\n";
    return 0;
}
