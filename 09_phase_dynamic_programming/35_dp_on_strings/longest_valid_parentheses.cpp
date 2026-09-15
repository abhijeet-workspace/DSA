// Longest Valid Parentheses — https://leetcode.com/problems/longest-valid-parentheses/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longestValidParentheses(std::string s) {
    const int n = static_cast<int>(s.size());
    std::vector<int> dp(n, 0);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (s[static_cast<size_t>(i)] != ')') continue;
        if (s[static_cast<size_t>(i - 1)] == '(') {
            dp[static_cast<size_t>(i)] = (i >= 2 ? dp[static_cast<size_t>(i - 2)] : 0) + 2;
        } else {
            const int j = i - dp[static_cast<size_t>(i - 1)] - 1;
            if (j >= 0 && s[static_cast<size_t>(j)] == '(') {
                dp[static_cast<size_t>(i)] = dp[static_cast<size_t>(i - 1)] + 2 +
                                             (j >= 1 ? dp[static_cast<size_t>(j - 1)] : 0);
            }
        }
        ans = std::max(ans, dp[static_cast<size_t>(i)]);
    }
    return ans;
}

int main() {
    std::cout << longestValidParentheses("(()") << " (expected 2)\n";
    std::cout << longestValidParentheses(")()())") << " (expected 4)\n";
    return 0;
}
