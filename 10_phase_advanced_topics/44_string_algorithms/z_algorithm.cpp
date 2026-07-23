// Z-algorithm — Z[i] = longest substring from i matching the prefix
// Maintain rightmost Z-box [L,R]; seed from Z[i-L] then extend
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> zFunction(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> Z(n, 0);
    int L = 0, R = 0;
    for (int i = 1; i < n; ++i) {
        if (i < R) Z[i] = std::min(R - i, Z[i - L]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) ++Z[i];
        if (i + Z[i] > R) {
            L = i;
            R = i + Z[i];
        }
    }
    return Z;
}

std::vector<int> searchWithZ(const std::string& pattern, const std::string& text) {
    std::string concat = pattern + "$" + text;
    auto Z = zFunction(concat);
    int m = static_cast<int>(pattern.size());
    std::vector<int> matches;
    for (int i = m + 1; i < static_cast<int>(concat.size()); ++i)
        if (Z[i] == m) matches.push_back(i - m - 1);
    return matches;
}

int main() {
    auto Z = zFunction("aabxaa");
    std::cout << "Z[4]=" << Z[4] << " (expected 2)\n";
    auto hits = searchWithZ("aa", "aabxaa");
    std::cout << "hits=" << hits.size() << " (expected 2)\n";
    return 0;
}
