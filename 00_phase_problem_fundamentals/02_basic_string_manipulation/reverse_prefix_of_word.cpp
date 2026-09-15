// Reverse Prefix of Word — LC 2000
// Reverse the segment s[0..idx] where idx is first occurrence of ch.
#include <algorithm>
#include <iostream>
#include <string>

std::string reversePrefix(std::string word, char ch) {
    const auto pos = word.find(ch);
    if (pos == std::string::npos)
        return word;
    std::reverse(word.begin(), word.begin() + static_cast<std::ptrdiff_t>(pos) + 1);
    return word;
}

int main() {
    std::cout << reversePrefix("abcdefd", 'd') << " (expected dcbaefd)\n";
    std::cout << reversePrefix("abcd", 'z') << " (expected abcd)\n";
    return 0;
}
