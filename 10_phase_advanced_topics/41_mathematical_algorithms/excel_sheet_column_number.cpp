// Excel Sheet Column Number — https://leetcode.com/problems/excel-sheet-column-number/
// Base-26 Horner with A=1..Z=26.
#include <iostream>
#include <string>

int titleToNumber(const std::string& columnTitle) {
    int ans = 0;
    for (char c : columnTitle) ans = ans * 26 + (c - 'A' + 1);
    return ans;
}

int main() {
    std::cout << titleToNumber("A") << " (expected 1)\n"
              << titleToNumber("AB") << " (expected 28)\n"
              << titleToNumber("ZY") << " (expected 701)\n";
    return 0;
}
