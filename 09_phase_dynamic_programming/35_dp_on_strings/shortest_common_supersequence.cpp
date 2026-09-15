// Shortest Common Supersequence — https://leetcode.com/problems/shortest-common-supersequence/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string shortestCommonSupersequence(std::string str1, std::string str2) {
    const int n = static_cast<int>(str1.size()), m = static_cast<int>(str2.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = str1[static_cast<size_t>(i - 1)] == str2[static_cast<size_t>(j - 1)]
                           ? dp[i - 1][j - 1] + 1
                           : std::max(dp[i - 1][j], dp[i][j - 1]);
    std::string ans;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (str1[static_cast<size_t>(i - 1)] == str2[static_cast<size_t>(j - 1)]) {
            ans.push_back(str1[static_cast<size_t>(i - 1)]);
            --i;
            --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            ans.push_back(str1[static_cast<size_t>(i - 1)]);
            --i;
        } else {
            ans.push_back(str2[static_cast<size_t>(j - 1)]);
            --j;
        }
    }
    while (i > 0)
        ans.push_back(str1[static_cast<size_t>(--i)]);
    while (j > 0)
        ans.push_back(str2[static_cast<size_t>(--j)]);
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::cout << shortestCommonSupersequence("abac", "cab") << " (expected cabac)\n";
    return 0;
}
