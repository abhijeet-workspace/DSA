// Ones and Zeroes — https://leetcode.com/problems/ones-and-zeroes/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int findMaxForm(std::vector<std::string>& strs, int m, int n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (const auto& s : strs) {
        int zeros = 0, ones = 0;
        for (char c : s)
            (c == '0' ? zeros : ones)++;
        for (int i = m; i >= zeros; --i) {
            for (int j = n; j >= ones; --j) {
                dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    std::max(dp[static_cast<size_t>(i)][static_cast<size_t>(j)],
                             dp[static_cast<size_t>(i - zeros)][static_cast<size_t>(j - ones)] + 1);
            }
        }
    }
    return dp[static_cast<size_t>(m)][static_cast<size_t>(n)];
}

int main() {
    std::vector<std::string> strs{"10", "0001", "111001", "1", "0"};
    std::cout << findMaxForm(strs, 5, 3) << " (expected 4)\n";
    return 0;
}
