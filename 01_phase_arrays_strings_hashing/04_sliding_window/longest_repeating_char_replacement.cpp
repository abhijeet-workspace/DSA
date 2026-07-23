// Longest Repeating Character Replacement — LC 424
// Window valid while (len − maxFreq) ≤ k replacements.
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

int characterReplacement(const std::string& s, int k) {
    std::array<int, 26> freq{};
    int left = 0, maxFreq = 0, best = 0;
    for (int right = 0; right < static_cast<int>(s.size()); ++right) {
        const int idx = s[static_cast<size_t>(right)] - 'A';
        maxFreq = std::max(maxFreq, ++freq[static_cast<size_t>(idx)]);
        while (right - left + 1 - maxFreq > k) {
            --freq[static_cast<size_t>(s[static_cast<size_t>(left)] - 'A')];
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    std::cout << characterReplacement("ABAB", 2) << " (expected 4)\n"
              << characterReplacement("AABABBA", 1) << " (expected 4)\n";
    return 0;
}
