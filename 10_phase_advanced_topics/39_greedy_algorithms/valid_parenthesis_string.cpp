// Valid Parenthesis String — https://leetcode.com/problems/valid-parenthesis-string/
// Track possible open-count range; '*' widens lo/hi.
#include <iostream>
#include <string>
#include <algorithm>

bool checkValidString(const std::string& s) {
    int lo = 0, hi = 0; // min/max possible open count
    for (char c : s) {
        if (c == '(') {
            ++lo;
            ++hi;
        } else if (c == ')') {
            lo = std::max(lo - 1, 0);
            --hi;
        } else { // '*' as ) or empty or (
            lo = std::max(lo - 1, 0);
            ++hi;
        }
        if (hi < 0) return false; // too many ')'
    }
    return lo == 0;
}

int main() {
    std::cout << std::boolalpha << checkValidString("(*))") << " (expected true)\n";
    return 0;
}
