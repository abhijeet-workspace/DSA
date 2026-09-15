// Reduce Array Size to The Half — LC 1338
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int minSetSize(const std::vector<int>& arr) {
    std::unordered_map<int, int> freq;
    for (int x : arr)
        ++freq[x];
    std::vector<int> counts;
    counts.reserve(freq.size());
    for (const auto& [_, c] : freq)
        counts.push_back(c);
    std::sort(counts.begin(), counts.end(), std::greater<int>());
    const int need = static_cast<int>(arr.size()) / 2;
    int removed = 0, sets = 0;
    for (int c : counts) {
        removed += c;
        ++sets;
        if (removed >= need)
            return sets;
    }
    return sets;
}

int main() {
    std::cout << minSetSize({3, 3, 3, 3, 5, 5, 5, 2, 2, 7}) << " (expected 2)\n";
    std::cout << minSetSize({7, 7, 7, 7, 7, 7}) << " (expected 1)\n";
    return 0;
}
