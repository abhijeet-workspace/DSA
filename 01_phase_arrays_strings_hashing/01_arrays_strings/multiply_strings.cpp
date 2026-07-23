// Multiply Strings — https://leetcode.com/problems/multiply-strings/
// Multiply two non-negative integers given as strings; return product as string.
#include <iostream>
#include <vector>
#include <string>

std::string multiply(std::string num1, std::string num2) {
    const int m = static_cast<int>(num1.size());
    const int n = static_cast<int>(num2.size());
    std::vector<int> a(static_cast<size_t>(m + n), 0); // digit positions
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            const int mul = (num1[static_cast<size_t>(i)] - '0') * (num2[static_cast<size_t>(j)] - '0')
                            + a[static_cast<size_t>(i + j + 1)];
            a[static_cast<size_t>(i + j + 1)] = mul % 10; // ones place
            a[static_cast<size_t>(i + j)] += mul / 10; // carry
        }
    }
    std::string s;
    for (int x : a) {
        if (s.empty() && x == 0) continue; // skip leading zeros
        s.push_back(static_cast<char>(x + '0'));
    }
    return s.empty() ? "0" : s;
}

int main() {
    std::cout << multiply("123", "456") << " (expected 56088)\n";
    return 0;
}
