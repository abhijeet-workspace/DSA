// Valid Anagram — LC 242
// Same letter multiset; 26-count array for lowercase a-z.
#include <iostream>
#include <string>
#include <array>

bool isAnagram(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) return false;
    std::array<int, 26> freq{};
    for (char c : s) ++freq[static_cast<size_t>(c - 'a')];
    for (char c : t) {
        if (--freq[static_cast<size_t>(c - 'a')] < 0) return false;
    }
    return true;
}

int main() {
    std::cout << std::boolalpha
              << isAnagram("anagram", "nagaram") << " (expected true)\n"
              << isAnagram("rat", "car") << " (expected false)\n";
    return 0;
}
