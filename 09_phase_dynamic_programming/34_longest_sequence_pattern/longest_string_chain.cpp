// Longest String Chain — https://leetcode.com/problems/longest-string-chain/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int longestStrChain(std::vector<std::string>& words) {
    std::sort(words.begin(), words.end(),
              [](const std::string& a, const std::string& b) { return a.size() < b.size(); });
    std::unordered_map<std::string, int> best;
    int ans = 1;
    for (const auto& w : words) {
        int cur = 1;
        for (size_t i = 0; i < w.size(); ++i) {
            std::string pred = w.substr(0, i) + w.substr(i + 1);
            auto it = best.find(pred);
            if (it != best.end()) cur = std::max(cur, it->second + 1);
        }
        best[w] = cur;
        ans = std::max(ans, cur);
    }
    return ans;
}

int main() {
    std::vector<std::string> words{"a", "b", "ba", "bca", "bda", "bdca"};
    std::cout << longestStrChain(words) << " (expected 4)\n";
    return 0;
}
