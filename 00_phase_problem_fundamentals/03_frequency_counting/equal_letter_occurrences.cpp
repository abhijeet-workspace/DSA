// Check if All Characters Have Equal Number of Occurrences — LC 1941
#include <iostream>
#include <string>

bool areOccurrencesEqual(const std::string& s) {
    int freq[26] = {};
    for (char c : s) ++freq[c - 'a'];
    int need = -1;
    for (int c : freq) {
        if (c == 0) continue;
        if (need == -1) need = c;
        else if (c != need) return false;
    }
    return true;
}

int main() {
    std::cout << std::boolalpha
              << areOccurrencesEqual("abacbc") << " (expected true)\n"
              << areOccurrencesEqual("aaabb") << " (expected false)\n";
    return 0;
}
