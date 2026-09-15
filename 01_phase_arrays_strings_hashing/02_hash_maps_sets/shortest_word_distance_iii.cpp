// Shortest Word Distance III — https://leetcode.com/problems/shortest-word-distance-iii/
// Like I, but word1 may equal word2 (distinct occurrences).
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int shortestWordDistance(const std::vector<std::string>& wordsDict, const std::string& word1,
                         const std::string& word2) {
    int best = static_cast<int>(wordsDict.size());
    int prev = -1;
    const bool same = (word1 == word2);
    for (int i = 0; i < static_cast<int>(wordsDict.size()); ++i) {
        const std::string& w = wordsDict[static_cast<size_t>(i)];
        if (w != word1 && w != word2)
            continue;
        if (prev != -1 && (same || w != wordsDict[static_cast<size_t>(prev)])) {
            best = std::min(best, i - prev);
        }
        prev = i;
    }
    return best;
}

int main() {
    const std::vector<std::string> w = {"practice", "makes", "perfect", "coding", "makes"};
    std::cout << shortestWordDistance(w, "makes", "coding") << " (expected 1)\n";
    std::cout << shortestWordDistance(w, "makes", "makes") << " (expected 3)\n";
    return 0;
}
