// String to Integer (atoi) — https://leetcode.com/problems/string-to-integer-atoi/
// Parse a 32-bit signed integer from a string with whitespace, sign, and overflow clamping.
#include <climits>
#include <iostream>
#include <string>

int myAtoi(const std::string& s) {
    const int n = static_cast<int>(s.size());
    int i = 0;
    while (i < n && s[static_cast<size_t>(i)] == ' ') {
        ++i;
    }
    int sign = 1;
    if (i < n && (s[static_cast<size_t>(i)] == '+' || s[static_cast<size_t>(i)] == '-')) {
        sign = s[static_cast<size_t>(i)] == '-' ? -1 : 1;
        ++i;
    }
    long long val = 0;
    while (i < n && s[static_cast<size_t>(i)] >= '0' && s[static_cast<size_t>(i)] <= '9') {
        val = val * 10 + (s[static_cast<size_t>(i)] - '0');
        if (sign == 1 && val > INT_MAX) {
            return INT_MAX;
        }
        if (sign == -1 && -val < INT_MIN) {
            return INT_MIN;
        }
        ++i;
    }
    return static_cast<int>(sign * val);
}

int main() {
    std::cout << myAtoi("42") << " (expected 42)\n";
    std::cout << myAtoi("   -42") << " (expected -42)\n";
    std::cout << myAtoi("4193 with words") << " (expected 4193)\n";
    std::cout << myAtoi("9123456789") << " (expected 2147483647)\n";
    return 0;
}
