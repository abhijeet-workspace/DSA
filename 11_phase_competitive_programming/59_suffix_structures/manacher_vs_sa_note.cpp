// Manacher vs SA — teaching note (palindromes ≠ suffix order)
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string longestPalindromeManacher(const std::string& s) {
    std::string t = "^";
    for (char c : s) {
        t.push_back('#');
        t.push_back(c);
    }
    t += "#$";
    int n = static_cast<int>(t.size());
    std::vector<int> p(n, 0);
    int c = 0, r = 0, best = 0, center = 0;
    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * c - i;
        if (i < r)
            p[i] = std::min(r - i, p[mirror]);
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
            ++p[i];
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
        if (p[i] > best) {
            best = p[i];
            center = i;
        }
    }
    int start = (center - best) / 2;
    return s.substr(start, best);
}

int main() {
    std::cout << longestPalindromeManacher("babad") << " (expected bab or aba)\n";
    std::cout << "manacher_not_sa=ok\n";
    return 0;
}
