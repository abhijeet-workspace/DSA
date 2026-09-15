// Is Subsequence — LC 392
// Walk t once; advance s only on matches. s is subsequence iff fully consumed.
#include <iostream>
#include <string>

bool isSubsequence(const std::string& s, const std::string& t) {
    size_t i = 0;
    for (size_t j = 0; j < t.size() && i < s.size(); ++j) {
        if (s[i] == t[j])
            ++i;
    }
    return i == s.size();
}

int main() {
    std::cout << std::boolalpha << isSubsequence("abc", "ahbgdc") << " (expected true)\n"
              << isSubsequence("axc", "ahbgdc") << " (expected false)\n"
              << isSubsequence("", "ahbgdc") << " (expected true)\n";
    return 0;
}
