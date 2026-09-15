// Palindrome Partitioning II — https://leetcode.com/problems/palindrome-partitioning-ii/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int minCut(std::string s) {
    const int n = static_cast<int>(s.size());
    std::vector<std::vector<char>> isPal(n, std::vector<char>(n, 0));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            isPal[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                (s[static_cast<size_t>(i)] == s[static_cast<size_t>(j)]) &&
                (j - i < 2 || isPal[static_cast<size_t>(i + 1)][static_cast<size_t>(j - 1)]);
        }
    }
    std::vector<int> cuts(n + 1, 0);
    for (int i = 0; i <= n; ++i) cuts[static_cast<size_t>(i)] = i - 1;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i <= j; ++i) {
            if (isPal[static_cast<size_t>(i)][static_cast<size_t>(j)]) {
                cuts[static_cast<size_t>(j + 1)] =
                    std::min(cuts[static_cast<size_t>(j + 1)], cuts[static_cast<size_t>(i)] + 1);
            }
        }
    }
    return cuts[static_cast<size_t>(n)];
}

int main() {
    std::cout << minCut("aab") << " (expected 1)\n";
    std::cout << minCut("a") << " (expected 0)\n";
    return 0;
}
