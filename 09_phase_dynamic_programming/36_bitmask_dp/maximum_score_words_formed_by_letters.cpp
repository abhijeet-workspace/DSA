// Maximum Score Words Formed by Letters — https://leetcode.com/problems/maximum-score-words-formed-by-letters/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
    const int n = static_cast<int>(words.size());
    std::vector<int> have(26, 0);
    for (char c : letters) have[static_cast<size_t>(c - 'a')]++;
    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        std::vector<int> need(26, 0);
        int sc = 0;
        bool ok = true;
        for (int i = 0; i < n && ok; ++i) {
            if (!(mask & (1 << i))) continue;
            for (char c : words[static_cast<size_t>(i)]) {
                const int k = c - 'a';
                need[static_cast<size_t>(k)]++;
                sc += score[static_cast<size_t>(k)];
                if (need[static_cast<size_t>(k)] > have[static_cast<size_t>(k)]) ok = false;
            }
        }
        if (ok) ans = std::max(ans, sc);
    }
    return ans;
}

int main() {
    std::vector<std::string> words{"dog", "cat", "dad", "good"};
    std::vector<char> letters{'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    std::vector<int> score{1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::cout << maxScoreWords(words, letters, score) << " (expected 23)\n";
    return 0;
}
