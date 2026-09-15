// Add Binary — https://leetcode.com/problems/add-binary/
// Right-to-left bit add with carry; reverse at the end.
#include <algorithm>
#include <iostream>
#include <string>

std::string addBinary(std::string a, std::string b) {
    std::string ans;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += a[static_cast<size_t>(i--)] - '0';
        if (j >= 0)
            sum += b[static_cast<size_t>(j--)] - '0';
        ans.push_back(static_cast<char>((sum % 2) + '0'));
        carry = sum / 2;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::cout << addBinary("11", "1") << " (expected 100)\n"
              << addBinary("1010", "1011") << " (expected 10101)\n"
              << addBinary("0", "0") << " (expected 0)\n"
              << addBinary("111", "1") << " (expected 1000)\n";
    return 0;
}
