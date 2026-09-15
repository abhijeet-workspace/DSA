// Repeated Substring Pattern — https://leetcode.com/problems/repeated-substring-pattern/
// s is repeated pattern iff s occurs inside (s+s) at index in (0, n).
#include <iostream>
#include <string>

bool repeatedSubstringPattern(const std::string& s) {
    const int n = static_cast<int>(s.size());
    if (n < 2) return false;
    std::string ss = s + s;
    return ss.find(s, 1) < static_cast<size_t>(n);
}

int main() {
    std::cout << std::boolalpha << repeatedSubstringPattern("abab") << " (expected true)\n"
              << repeatedSubstringPattern("aba") << " (expected false)\n"
              << repeatedSubstringPattern("abcabcabcabc") << " (expected true)\n";
    return 0;
}
