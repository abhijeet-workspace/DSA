// Unique Number of Occurrences — LC 1207
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool uniqueOccurrences(const std::vector<int>& arr) {
    std::unordered_map<int, int> freq;
    for (int x : arr) ++freq[x];
    std::unordered_set<int> seen;
    for (const auto& [_, c] : freq) {
        if (!seen.insert(c).second) return false;
    }
    return true;
}

int main() {
    std::cout << std::boolalpha
              << uniqueOccurrences({1, 2, 2, 1, 1, 3}) << " (expected true)\n"
              << uniqueOccurrences({1, 2}) << " (expected false)\n";
    return 0;
}
