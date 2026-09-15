// Palindromic Substrings — https://leetcode.com/problems/palindromic-substrings/
#include <iostream>
#include <string>

int countSubstrings(std::string s) {
    const int n = static_cast<int>(s.size());
    int ans = 0;
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[static_cast<size_t>(l)] == s[static_cast<size_t>(r)]) {
            ++ans; --l; ++r;
        }
    };
    for (int i = 0; i < n; ++i) { expand(i, i); expand(i, i + 1); }
    return ans;
}

int main() {
    std::cout << countSubstrings("abc") << " (expected 3)\n";
    std::cout << countSubstrings("aaa") << " (expected 6)\n";
    return 0;
}
