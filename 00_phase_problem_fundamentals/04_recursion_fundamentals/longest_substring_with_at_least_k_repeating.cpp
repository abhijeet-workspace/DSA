// Longest Substring with At Least K Repeating Characters — LC 395
// Divide-and-conquer recursion.
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

int longestSubstring(const std::string& s, int k) {
    std::function<int(int, int)> solve = [&](int L, int R) -> int {
        if (R - L < k) return 0;
        int freq[26] = {};
        for (int i = L; i < R; ++i) ++freq[s[static_cast<size_t>(i)] - 'a'];
        for (int mid = L; mid < R; ++mid) {
            if (freq[s[static_cast<size_t>(mid)] - 'a'] < k) {
                int best = 0;
                int start = L;
                for (int i = L; i <= R; ++i) {
                    bool isSplit = (i == R) || (freq[s[static_cast<size_t>(i)] - 'a'] < k);
                    if (isSplit) {
                        best = std::max(best, solve(start, i));
                        start = i + 1;
                    }
                }
                return best;
            }
        }
        return R - L;
    };
    return solve(0, static_cast<int>(s.size()));
}

int main() {
    std::cout << longestSubstring("aaabb", 3) << " (expected 3)\n";
    std::cout << longestSubstring("ababbc", 2) << " (expected 5)\n";
    return 0;
}
