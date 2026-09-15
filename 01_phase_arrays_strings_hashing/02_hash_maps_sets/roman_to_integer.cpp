// Roman to Integer — https://leetcode.com/problems/roman-to-integer/
// Map each symbol; subtract when a smaller value precedes a larger one.
#include <iostream>
#include <string>
#include <unordered_map>

int romanToInt(const std::string& s) {
    const std::unordered_map<char, int> val{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000},
    };
    int ans = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        const int cur = val.at(s[i]);
        if (i + 1 < s.size() && cur < val.at(s[i + 1])) {
            ans -= cur; // subtractive pair
        } else {
            ans += cur;
        }
    }
    return ans;
}

int main() {
    std::cout << romanToInt("III") << " (expected 3)\n"
              << romanToInt("LVIII") << " (expected 58)\n"
              << romanToInt("MCMXCIV") << " (expected 1994)\n";
    return 0;
}
