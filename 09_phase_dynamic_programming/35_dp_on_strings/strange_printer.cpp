// Strange Printer — https://leetcode.com/problems/strange-printer/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int strangePrinter(std::string s) {
    std::string t;
    for (char c : s) if (t.empty() || t.back() != c) t.push_back(c);
    const int n = static_cast<int>(t.size());
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) dp[static_cast<size_t>(i)][static_cast<size_t>(i)] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            const int j = i + len - 1;
            dp[static_cast<size_t>(i)][static_cast<size_t>(j)] = len;
            for (int k = i; k < j; ++k) {
                int val = dp[static_cast<size_t>(i)][static_cast<size_t>(k)] +
                          dp[static_cast<size_t>(k + 1)][static_cast<size_t>(j)];
                if (t[static_cast<size_t>(i)] == t[static_cast<size_t>(j)]) --val; // subtle; use standard:
                (void)val;
            }
            // standard recurrence
            dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                1 + dp[static_cast<size_t>(i + 1)][static_cast<size_t>(j)];
            for (int k = i + 1; k <= j; ++k) {
                if (t[static_cast<size_t>(k)] == t[static_cast<size_t>(i)]) {
                    dp[static_cast<size_t>(i)][static_cast<size_t>(j)] = std::min(
                        dp[static_cast<size_t>(i)][static_cast<size_t>(j)],
                        dp[static_cast<size_t>(i)][static_cast<size_t>(k - 1)] +
                            (k + 1 <= j ? dp[static_cast<size_t>(k + 1)][static_cast<size_t>(j)] : 0));
                }
            }
        }
    }
    return n == 0 ? 0 : dp[0][static_cast<size_t>(n - 1)];
}

int main() {
    std::cout << strangePrinter("aaabbb") << " (expected 2)\n";
    std::cout << strangePrinter("aba") << " (expected 2)\n";
    return 0;
}
