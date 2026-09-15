// Find All Anagrams in a String — LC 438
// Fixed window of |p|; collect start indices where 26-counts match.
#include <iostream>
#include <string>
#include <vector>

std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
    std::vector<int> ans;
    const int n = static_cast<int>(s.size());
    const int m = static_cast<int>(p.size());
    if (m > n)
        return ans;

    std::vector<int> need(26, 0), window(26, 0);
    for (char c : p)
        ++need[static_cast<size_t>(c - 'a')];
    for (int i = 0; i < m; ++i)
        ++window[static_cast<size_t>(s[static_cast<size_t>(i)] - 'a')];
    if (need == window)
        ans.push_back(0);

    for (int i = m; i < n; ++i) {
        ++window[static_cast<size_t>(s[static_cast<size_t>(i)] - 'a')];
        --window[static_cast<size_t>(s[static_cast<size_t>(i - m)] - 'a')];
        if (need == window)
            ans.push_back(i - m + 1);
    }
    return ans;
}

int main() {
    auto a = findAnagrams("cbaebabacd", "abc");
    std::cout << "[";
    for (size_t i = 0; i < a.size(); ++i)
        std::cout << a[i] << (i + 1 < a.size() ? "," : "");
    std::cout << "] (expected [0,6])\n";

    auto b = findAnagrams("abab", "ab");
    std::cout << "[";
    for (size_t i = 0; i < b.size(); ++i)
        std::cout << b[i] << (i + 1 < b.size() ? "," : "");
    std::cout << "] (expected [0,1,2])\n";
    return 0;
}
