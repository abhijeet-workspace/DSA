// Find Index of First Occurrence —
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ KMP search;
// return first match index or -1.
#include <iostream>
#include <string>
#include <vector>

std::vector<int> lpsOf(const std::string& p) {
    int m = static_cast<int>(p.size());
    std::vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m;) {
        if (p[i] == p[len])
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    return lps;
}

int strStr(const std::string& haystack, const std::string& needle) {
    if (needle.empty())
        return 0;
    auto lps = lpsOf(needle);
    int n = static_cast<int>(haystack.size()), m = static_cast<int>(needle.size());
    for (int i = 0, j = 0; i < n;) {
        if (haystack[i] == needle[j]) {
            ++i;
            ++j;
        }
        if (j == m)
            return i - m;
        if (i < n && haystack[i] != needle[j]) {
            if (j)
                j = lps[j - 1];
            else
                ++i;
        }
    }
    return -1;
}

int main() {
    std::cout << strStr("sadbutsad", "sad") << " (expected 0)\n"
              << strStr("leetcode", "leeto") << " (expected -1)\n";
    return 0;
}
