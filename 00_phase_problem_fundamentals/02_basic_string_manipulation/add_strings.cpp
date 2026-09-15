// Add Strings — LC 415
// Add non-negative integers given as strings; return sum as string.
#include <algorithm>
#include <iostream>
#include <string>

std::string addStrings(const std::string& num1, const std::string& num2) {
    int i = static_cast<int>(num1.size()) - 1;
    int j = static_cast<int>(num2.size()) - 1;
    int carry = 0;
    std::string ans;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += num1[static_cast<size_t>(i--)] - '0';
        if (j >= 0)
            sum += num2[static_cast<size_t>(j--)] - '0';
        ans.push_back(static_cast<char>('0' + (sum % 10)));
        carry = sum / 10;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::cout << addStrings("11", "123") << " (expected 134)\n";
    std::cout << addStrings("456", "77") << " (expected 533)\n";
    return 0;
}
