// Length of Last Word — LC 58
// Skip trailing spaces, then count until the previous space or start.
#include <iostream>
#include <string>

int lengthOfLastWord(const std::string& s) {
    int i = static_cast<int>(s.size()) - 1;
    while (i >= 0 && s[static_cast<size_t>(i)] == ' ') --i;
    int len = 0;
    while (i >= 0 && s[static_cast<size_t>(i)] != ' ') {
        ++len;
        --i;
    }
    return len;
}

int main() {
    std::cout << lengthOfLastWord("Hello World") << " (expected 5)\n";
    std::cout << lengthOfLastWord("   fly me   to   the moon  ") << " (expected 4)\n";
    return 0;
}
