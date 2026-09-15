// Longest Happy Prefix — https://leetcode.com/problems/longest-happy-prefix/
// LPS[n-1] = length of longest proper prefix that is suffix.
#include <iostream>
#include <string>
#include <vector>

std::string longestPrefix(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n;) {
        if (s[i] == s[len])
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    return s.substr(0, lps.back());
}

int main() {
    std::cout << longestPrefix("level") << " (expected l)\n"
              << longestPrefix("ababab") << " (expected abab)\n";
    return 0;
}
