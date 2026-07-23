// Distinct Subsequences — https://leetcode.com/problems/distinct-subsequences/
// Count ways to form t as a subsequence of s.
#include <iostream>
#include <string>
#include <vector>

int numDistinct(std::string s, std::string t) {
    const int n = static_cast<int>(t.size());
    std::vector<unsigned long long> dp(n + 1, 0); // ways to form t[0..j)
    dp[0] = 1; // empty t always one way
    for (char c : s) {
        for (int j = n; j >= 1; --j) { // reverse avoids reuse of same s char
            if (c == t[static_cast<size_t>(j - 1)]) {
                dp[static_cast<size_t>(j)] += dp[static_cast<size_t>(j - 1)];
            }
        }
    }
    return static_cast<int>(dp[static_cast<size_t>(n)]);
}

int main() {
    std::cout << numDistinct("rabbbit", "rabbit") << " (expected 3)\n";
    return 0;
}
