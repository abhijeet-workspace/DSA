// Reverse Words in a String — LC 151
// Trim, collapse spaces, reverse whole string, then reverse each word.
#include <algorithm>
#include <iostream>
#include <string>

std::string reverseWords(std::string s) {
    // 1) Clean: single spaces, no leading/trailing.
    std::string cleaned;
    cleaned.reserve(s.size());
    bool spacePending = false;
    for (char c : s) {
        if (c == ' ') {
            if (!cleaned.empty())
                spacePending = true;
        } else {
            if (spacePending) {
                cleaned.push_back(' ');
                spacePending = false;
            }
            cleaned.push_back(c);
        }
    }
    s.swap(cleaned);

    std::reverse(s.begin(), s.end());
    const int n = static_cast<int>(s.size());
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && s[static_cast<size_t>(j)] != ' ')
            ++j;
        std::reverse(s.begin() + i, s.begin() + j);
        i = j + 1;
    }
    return s;
}

int main() {
    std::cout << "[" << reverseWords("  hello world  ") << "] (expected [world hello])\n";
    std::cout << "[" << reverseWords("a good   example") << "] (expected [example good a])\n";
    return 0;
}
