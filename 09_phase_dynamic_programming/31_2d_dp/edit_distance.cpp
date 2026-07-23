// Edit Distance — https://leetcode.com/problems/edit-distance/
// Min insert/delete/replace ops to turn word1 into word2.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int minDistance(std::string word1, std::string word2) {
    const int n = static_cast<int>(word1.size());
    const int m = static_cast<int>(word2.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i; // delete all of word1 prefix
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j; // insert all of word2 prefix
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (word1[static_cast<size_t>(i - 1)] == word2[static_cast<size_t>(j - 1)]) {
                dp[i][j] = dp[i - 1][j - 1]; // match, no op
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j],     // delete
                                         dp[i][j - 1],     // insert
                                         dp[i - 1][j - 1]}); // replace
            }
        }
    }
    return dp[n][m];
}

int main() {
    std::cout << minDistance("horse", "ros") << " (expected 3)\n";
    return 0;
}
