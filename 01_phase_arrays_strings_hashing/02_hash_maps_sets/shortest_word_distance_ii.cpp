// Shortest Word Distance II — https://leetcode.com/problems/shortest-word-distance-ii/
// Preprocess dictionary; answer many shortestDistance queries.
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class WordDistance {
    std::unordered_map<std::string, std::vector<int>> pos_;

public:
    explicit WordDistance(const std::vector<std::string>& wordsDict) {
        for (int i = 0; i < static_cast<int>(wordsDict.size()); ++i) {
            pos_[wordsDict[static_cast<size_t>(i)]].push_back(i);
        }
    }

    int shortest(const std::string& word1, const std::string& word2) {
        const auto& a = pos_.at(word1);
        const auto& b = pos_.at(word2);
        int i = 0, j = 0, best = INT_MAX / 4;
        while (i < static_cast<int>(a.size()) && j < static_cast<int>(b.size())) {
            best = std::min(best, std::abs(a[static_cast<size_t>(i)] - b[static_cast<size_t>(j)]));
            if (a[static_cast<size_t>(i)] < b[static_cast<size_t>(j)]) ++i;
            else ++j;
        }
        return best;
    }
};

int main() {
    WordDistance wd({"practice", "makes", "perfect", "coding", "makes"});
    std::cout << wd.shortest("coding", "practice") << " (expected 3)\n";
    std::cout << wd.shortest("makes", "coding") << " (expected 1)\n";
    return 0;
}
