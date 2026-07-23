// Word Ladder — https://leetcode.com/problems/word-ladder/
// Shortest transformation length beginWord → endWord; one letter change per step.
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

int ladderLength(std::string beginWord, std::string endWord,
                 const std::vector<std::string>& wordList) {
    std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) {
        return 0;
    }

    std::queue<std::pair<std::string, int>> q;
    q.push({beginWord, 1}); // word, ladder length

    while (!q.empty()) {
        auto [word, level] = q.front();
        q.pop();
        if (word == endWord) {
            return level;
        }
        for (int i = 0; i < static_cast<int>(word.size()); ++i) {
            const char orig = word[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                word[i] = c;
                if (dict.count(word)) {
                    dict.erase(word); // visited
                    q.push({word, level + 1});
                }
            }
            word[i] = orig; // restore
        }
    }
    return 0;
}

int main() {
    const std::string beginWord = "hit";
    const std::string endWord = "cog";
    const std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    std::cout << ladderLength(beginWord, endWord, wordList) << " (expected 5)\n";
    return 0;
}
