// Word Break — https://leetcode.com/problems/word-break/
// True if s can be segmented into dictionary words (reuse allowed).
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
    const std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
    const int n = static_cast<int>(s.size());
    std::vector<bool> dp(static_cast<size_t>(n) + 1, false);
    dp[0] = true; // empty prefix
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[static_cast<size_t>(j)]
                && dict.count(s.substr(static_cast<size_t>(j),
                                       static_cast<size_t>(i - j)))) {
                dp[static_cast<size_t>(i)] = true;
                break;
            }
        }
    }
    return dp[static_cast<size_t>(n)];
}

int main() {
    std::cout << std::boolalpha
              << wordBreak("leetcode", {"leet", "code"}) << " (expected true)\n"
              << wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"})
              << " (expected false)\n";
    return 0;
}
