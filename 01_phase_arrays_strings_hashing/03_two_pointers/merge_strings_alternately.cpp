// Merge Strings Alternately — LC 1768
// Alternate chars from word1/word2; append leftover of the longer.
#include <iostream>
#include <string>

std::string mergeAlternately(const std::string& word1, const std::string& word2) {
    std::string ans;
    ans.reserve(word1.size() + word2.size());
    size_t i = 0, j = 0;
    while (i < word1.size() || j < word2.size()) {
        if (i < word1.size())
            ans.push_back(word1[i++]);
        if (j < word2.size())
            ans.push_back(word2[j++]);
    }
    return ans;
}

int main() {
    std::cout << mergeAlternately("abc", "pqr") << " (expected apbqcr)\n"
              << mergeAlternately("ab", "pqrs") << " (expected apbqrs)\n";
    return 0;
}
