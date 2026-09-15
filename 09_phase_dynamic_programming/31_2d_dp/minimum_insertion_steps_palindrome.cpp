// Minimum Insertion Steps to Make a String Palindrome —
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Answer = n - LPS; LPS = LCS(s, reverse(s)).
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

static int lcsLen(const std::string& a, const std::string& b) {
    const int m = static_cast<int>(a.size());
    const int n = static_cast<int>(b.size());
    std::vector<int> prev(static_cast<size_t>(n) + 1, 0);
    std::vector<int> curr(static_cast<size_t>(n) + 1, 0);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[static_cast<size_t>(i - 1)] == b[static_cast<size_t>(j - 1)]) {
                curr[static_cast<size_t>(j)] = 1 + prev[static_cast<size_t>(j - 1)];
            } else {
                curr[static_cast<size_t>(j)] =
                    std::max(prev[static_cast<size_t>(j)], curr[static_cast<size_t>(j - 1)]);
            }
        }
        prev.swap(curr);
        std::fill(curr.begin(), curr.end(), 0);
    }
    return prev[static_cast<size_t>(n)];
}

int minInsertions(const std::string& s) {
    std::string rev = s;
    std::reverse(rev.begin(), rev.end());
    const int n = static_cast<int>(s.size());
    return n - lcsLen(s, rev); // chars not in LPS need a matching insert
}

int main() {
    std::cout << minInsertions("zzazz") << " (expected 0)\n"
              << minInsertions("mbadm") << " (expected 2)\n"
              << minInsertions("leetcode") << " (expected 5)\n";
    return 0;
}
