// Decode Ways — https://leetcode.com/problems/decode-ways/
// Digits map A=1..Z=26; count ways to decode string s.
#include <iostream>
#include <string>

int numDecodings(const std::string& s) {
    if (s.empty() || s[0] == '0') {
        return 0;
    }
    int prev2 = 1; // ways for empty prefix
    int prev1 = 1; // ways for first char
    for (size_t i = 1; i < s.size(); ++i) {
        int cur = 0;
        if (s[i] != '0') {
            cur += prev1; // single digit
        }
        const int two = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if (two >= 10 && two <= 26) {
            cur += prev2; // two-digit code
        }
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    std::cout << numDecodings("12") << " (expected 2)\n"
              << numDecodings("226") << " (expected 3)\n"
              << numDecodings("06") << " (expected 0)\n";
    return 0;
}
