// Integer to Roman — https://leetcode.com/problems/integer-to-roman/
// Greedy: repeatedly subtract the largest Roman value that still fits.
#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::string intToRoman(int num) {
    static const std::vector<std::pair<int, const char*>> table{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"},
    };
    std::string ans;
    for (const auto& [val, sym] : table) {
        while (num >= val) {
            ans += sym;
            num -= val;
        }
    }
    return ans;
}

int main() {
    std::cout << intToRoman(3) << " (expected III)\n"
              << intToRoman(58) << " (expected LVIII)\n"
              << intToRoman(1994) << " (expected MCMXCIV)\n";
    return 0;
}
