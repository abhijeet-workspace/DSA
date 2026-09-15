// Custom Sort String — https://leetcode.com/problems/custom-sort-string/
// Sort s so characters appear in order of order; others keep any relative order.
#include <iostream>
#include <string>
#include <vector>

std::string customSortString(const std::string& order, const std::string& s) {
    std::vector<int> freq(26, 0);
    for (char c : s) ++freq[static_cast<size_t>(c - 'a')];
    std::string out;
    out.reserve(s.size());
    for (char c : order) {
        const size_t i = static_cast<size_t>(c - 'a');
        out.append(static_cast<size_t>(freq[i]), c);
        freq[i] = 0;
    }
    for (int i = 0; i < 26; ++i) {
        if (freq[static_cast<size_t>(i)] > 0) {
            out.append(static_cast<size_t>(freq[static_cast<size_t>(i)]),
                       static_cast<char>('a' + i));
        }
    }
    return out;
}

int main() {
    std::cout << customSortString("cba", "abcd") << " (expected cbad)\n";
    std::cout << customSortString("bcafg", "abcd") << " (expected bcad)\n";
    return 0;
}
