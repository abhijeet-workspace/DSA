// Longest Ideal Subsequence — https://leetcode.com/problems/longest-ideal-subsequence/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longestIdealString(std::string s, int k) {
    std::vector<int> best(26, 0);
    int ans = 0;
    for (char ch : s) {
        const int c = ch - 'a';
        int cur = 0;
        for (int p = std::max(0, c - k); p <= std::min(25, c + k); ++p)
            cur = std::max(cur, best[static_cast<size_t>(p)]);
        best[static_cast<size_t>(c)] = cur + 1;
        ans = std::max(ans, best[static_cast<size_t>(c)]);
    }
    return ans;
}

int main() {
    std::cout << longestIdealString("abcd", 3) << " (expected 4)\n";
    std::cout << longestIdealString("acfg", 2) << " (expected 2)\n";
    return 0;
}
