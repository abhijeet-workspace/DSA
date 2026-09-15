// Rotate String — https://leetcode.com/problems/rotate-string/
// goal is rotation of s iff same length and goal in s+s.
#include <iostream>
#include <string>

bool rotateString(const std::string& s, const std::string& goal) {
    return s.size() == goal.size() && (s + s).find(goal) != std::string::npos;
}

int main() {
    std::cout << std::boolalpha << rotateString("abcde", "cdeab") << " (expected true)\n"
              << rotateString("abcde", "abced") << " (expected false)\n";
    return 0;
}
