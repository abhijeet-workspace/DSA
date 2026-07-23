// Valid Palindrome — LC 125
// Skip non-alnum; compare lowercased chars from both ends.
#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(const std::string& s) {
    int L = 0;
    int R = static_cast<int>(s.size()) - 1;
    while (L < R) {
        while (L < R && !std::isalnum(static_cast<unsigned char>(s[static_cast<size_t>(L)]))) ++L;
        while (L < R && !std::isalnum(static_cast<unsigned char>(s[static_cast<size_t>(R)]))) --R;
        char a = static_cast<char>(std::tolower(static_cast<unsigned char>(s[static_cast<size_t>(L)])));
        char b = static_cast<char>(std::tolower(static_cast<unsigned char>(s[static_cast<size_t>(R)])));
        if (a != b) return false;
        ++L; --R;
    }
    return true;
}

int main() {
    std::cout << std::boolalpha
              << isPalindrome("A man, a plan, a canal: Panama") << " (expected true)\n"
              << isPalindrome("race a car") << " (expected false)\n";
    return 0;
}
