// Longest Common Prefix — https://leetcode.com/problems/longest-common-prefix/
// Vertical scan: shrink at the first index where any string differs.
#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    const std::string& first = strs[0];
    for (size_t i = 0; i < first.size(); ++i) {
        const char c = first[i];
        for (size_t j = 1; j < strs.size(); ++j) {
            if (i == strs[j].size() || strs[j][i] != c) {
                return first.substr(0, i);
            }
        }
    }
    return first;
}

int main() {
    std::cout << longestCommonPrefix({"flower", "flow", "flight"})
              << " (expected fl)\n"
              << longestCommonPrefix({"dog", "racecar", "car"})
              << " (expected )\n"
              << longestCommonPrefix({"a"})
              << " (expected a)\n"
              << longestCommonPrefix({"", "b"})
              << " (expected )\n"
              << longestCommonPrefix({"ab", "a"})
              << " (expected a)\n";
    return 0;
}
