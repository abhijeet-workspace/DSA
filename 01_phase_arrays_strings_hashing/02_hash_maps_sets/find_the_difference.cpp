// Find the Difference — LC 389
// t is s plus one extra char; XOR cancels matching pairs, leaves the extra.
#include <iostream>
#include <string>

char findTheDifference(const std::string& s, const std::string& t) {
    char diff = 0;
    for (char c : s) diff ^= c;
    for (char c : t) diff ^= c;
    return diff;
}

int main() {
    std::cout << findTheDifference("abcd", "abcde") << " (expected e)\n"
              << findTheDifference("", "y") << " (expected y)\n";
    return 0;
}
