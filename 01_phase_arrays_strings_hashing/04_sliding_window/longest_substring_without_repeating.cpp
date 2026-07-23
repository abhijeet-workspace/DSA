// Longest Substring Without Repeating — LC 3
// Expand right; on duplicate, jump left to lastIndex+1.
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> last;
    int left = 0, best = 0;
    for (int right = 0; right < static_cast<int>(s.size()); ++right) {
        const char c = s[static_cast<size_t>(right)];
        if (last.count(c) && last[c] >= left) left = last[c] + 1;
        last[c] = right;
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    std::cout << lengthOfLongestSubstring("abcabcbb") << " (expected 3)\n"
              << lengthOfLongestSubstring("bbbbb") << " (expected 1)\n"
              << lengthOfLongestSubstring("pwwkew") << " (expected 3)\n";
    return 0;
}
