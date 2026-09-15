// Check If Two String Arrays are Equivalent — LC 1662
// Compare concatenations without building full strings.
#include <iostream>
#include <string>
#include <vector>

bool arrayStringsAreEqual(const std::vector<std::string>& word1,
                          const std::vector<std::string>& word2) {
    size_t i = 0, j = 0;
    size_t p = 0, q = 0;
    while (i < word1.size() && j < word2.size()) {
        if (word1[i][p] != word2[j][q])
            return false;
        if (++p == word1[i].size()) {
            ++i;
            p = 0;
        }
        if (++q == word2[j].size()) {
            ++j;
            q = 0;
        }
    }
    return i == word1.size() && j == word2.size();
}

int main() {
    std::cout << std::boolalpha << arrayStringsAreEqual({"ab", "c"}, {"a", "bc"})
              << " (expected true)\n"
              << arrayStringsAreEqual({"a", "cb"}, {"ab", "c"}) << " (expected false)\n";
    return 0;
}
