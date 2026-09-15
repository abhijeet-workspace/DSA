// Check if the Sentence Is Pangram — LC 1832
// Fixed bool[26] presence table for letters a-z.
#include <iostream>
#include <string>

bool checkIfPangram(const std::string& sentence) {
    bool seen[26] = {};
    int got = 0;
    for (char c : sentence) {
        if (c < 'a' || c > 'z')
            continue;
        const int i = c - 'a';
        if (!seen[i]) {
            seen[i] = true;
            if (++got == 26)
                return true;
        }
    }
    return got == 26;
}

int main() {
    std::cout << std::boolalpha << checkIfPangram("thequickbrownfoxjumpsoverthelazydog")
              << " (expected true)\n"
              << checkIfPangram("leetcode") << " (expected false)\n";
    return 0;
}
