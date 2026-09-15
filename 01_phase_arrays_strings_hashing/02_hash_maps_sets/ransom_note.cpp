// Ransom Note — LC 383
// Build ransomNote from magazine letters; 26-count array.
#include <array>
#include <iostream>
#include <string>

bool canConstruct(const std::string& ransomNote, const std::string& magazine) {
    if (ransomNote.size() > magazine.size())
        return false;
    std::array<int, 26> freq{};
    for (char c : magazine)
        ++freq[static_cast<size_t>(c - 'a')];
    for (char c : ransomNote) {
        if (--freq[static_cast<size_t>(c - 'a')] < 0)
            return false;
    }
    return true;
}

int main() {
    std::cout << std::boolalpha << canConstruct("a", "b") << " (expected false)\n"
              << canConstruct("aa", "ab") << " (expected false)\n"
              << canConstruct("aa", "aab") << " (expected true)\n";
    return 0;
}
