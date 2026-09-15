// Repeated String Match — https://leetcode.com/problems/repeated-string-match/
// Build a*k with k <= |b|/|a|+2; KMP search for b.
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

bool containsKMP(const std::string& text, const std::string& pat) {
    if (pat.empty())
        return true;
    auto lps = lpsOf(pat);
    int n = static_cast<int>(text.size()), m = static_cast<int>(pat.size());
    for (int i = 0, j = 0; i < n;) {
        if (text[i] == pat[j]) {
            ++i;
            ++j;
        }
        if (j == m)
            return true;
        if (i < n && text[i] != pat[j]) {
            if (j)
                j = lps[j - 1];
            else
                ++i;
        }
    }
    return false;
}

int repeatedStringMatch(const std::string& a, const std::string& b) {
    std::string s = a;
    int k = 1;
    while (static_cast<int>(s.size()) < static_cast<int>(b.size())) {
        s += a;
        ++k;
    }
    if (containsKMP(s, b))
        return k;
    s += a;
    ++k;
    if (containsKMP(s, b))
        return k;
    return -1;
}

int main() {
    std::cout << repeatedStringMatch("abcd", "cdabcdab") << " (expected 3)\n"
              << repeatedStringMatch("a", "aa") << " (expected 2)\n";
    return 0;
}
