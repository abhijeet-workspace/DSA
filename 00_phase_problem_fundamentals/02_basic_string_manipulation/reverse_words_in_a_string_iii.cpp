// Reverse Words in a String III — LC 557
// Reverse each whitespace-separated word in place; spaces stay fixed.
#include <iostream>
#include <string>
#include <algorithm>

std::string reverseWords(std::string s) {
    const int n = static_cast<int>(s.size());
    int i = 0;
    while (i < n) {
        while (i < n && s[static_cast<size_t>(i)] == ' ') ++i;
        int j = i;
        while (j < n && s[static_cast<size_t>(j)] != ' ') ++j;
        std::reverse(s.begin() + i, s.begin() + j);
        i = j;
    }
    return s;
}

int main() {
    std::cout << reverseWords("Let's take LeetCode contest")
              << " (expected s'teL ekat edoCteeL tsetnoc)\n";
    return 0;
}
