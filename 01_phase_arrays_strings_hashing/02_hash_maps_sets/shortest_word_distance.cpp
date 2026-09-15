// Shortest Word Distance — https://leetcode.com/problems/shortest-word-distance/
// Minimum index distance between word1 and word2 in wordsDict (word1 != word2).
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int shortestDistance(const std::vector<std::string>& wordsDict,
                     const std::string& word1, const std::string& word2) {
    int i1 = -1, i2 = -1, best = static_cast<int>(wordsDict.size());
    for (int i = 0; i < static_cast<int>(wordsDict.size()); ++i) {
        if (wordsDict[static_cast<size_t>(i)] == word1) i1 = i;
        if (wordsDict[static_cast<size_t>(i)] == word2) i2 = i;
        if (i1 >= 0 && i2 >= 0) best = std::min(best, std::abs(i1 - i2));
    }
    return best;
}

int main() {
    const std::vector<std::string> w = {"practice", "makes", "perfect", "coding", "makes"};
    std::cout << shortestDistance(w, "coding", "practice") << " (expected 3)\n";
    std::cout << shortestDistance(w, "makes", "coding") << " (expected 1)\n";
    return 0;
}
