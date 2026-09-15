// Determine if String Halves Are Alike — LC 1704
// Equal vowel counts in s[0..n/2) and s[n/2..n).
#include <cctype>
#include <iostream>
#include <string>

static bool isVowel(char c) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool halvesAreAlike(const std::string& s) {
    const int n = static_cast<int>(s.size());
    int left = 0, right = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (isVowel(s[static_cast<size_t>(i)]))
            ++left;
    }
    for (int i = n / 2; i < n; ++i) {
        if (isVowel(s[static_cast<size_t>(i)]))
            ++right;
    }
    return left == right;
}

int main() {
    std::cout << std::boolalpha << halvesAreAlike("book") << " (expected true)\n"
              << halvesAreAlike("textbook") << " (expected false)\n";
    return 0;
}
