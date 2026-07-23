// Minimum Window Substring — LC 76
// Expand to cover need; shrink while valid; track shortest window.
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

std::string minWindow(const std::string& s, const std::string& t) {
    if (t.empty() || s.size() < t.size()) return "";
    std::unordered_map<char, int> need;
    for (char c : t) ++need[c];
    const int required = static_cast<int>(need.size());
    int formed = 0;
    std::unordered_map<char, int> window;
    int bestLen = INT_MAX, bestL = 0, left = 0;
    for (int right = 0; right < static_cast<int>(s.size()); ++right) {
        const char c = s[static_cast<size_t>(right)];
        ++window[c];
        if (need.count(c) && window[c] == need[c]) ++formed;
        while (left <= right && formed == required) {
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestL = left;
            }
            const char d = s[static_cast<size_t>(left)];
            --window[d];
            if (need.count(d) && window[d] < need[d]) --formed;
            ++left;
        }
    }
    return bestLen == INT_MAX
               ? ""
               : s.substr(static_cast<size_t>(bestL), static_cast<size_t>(bestLen));
}

int main() {
    std::cout << minWindow("ADOBECODEBANC", "ABC") << " (expected BANC)\n"
              << minWindow("a", "a") << " (expected a)\n"
              << minWindow("a", "aa") << " (expected empty)\n";
    return 0;
}
