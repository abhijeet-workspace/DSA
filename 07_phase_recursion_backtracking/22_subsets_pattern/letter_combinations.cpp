// Letter Combinations of a Phone Number — https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Map digits 2–9 to letters; return all length-|digits| strings.
#include <iostream>
#include <string>
#include <vector>

namespace {
const std::vector<std::string> kKeypad = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
};
} // namespace

void backtrack(const std::string& digits, int index, std::string& current,
               std::vector<std::string>& result) {
    if (index == static_cast<int>(digits.size())) {
        result.push_back(current); // one full mapping
        return;
    }
    const std::string& letters = kKeypad[static_cast<size_t>(digits[static_cast<size_t>(index)] - '0')];
    for (char c : letters) {
        current.push_back(c);
        backtrack(digits, index + 1, current, result);
        current.pop_back();
    }
}

std::vector<std::string> letterCombinations(const std::string& digits) {
    if (digits.empty()) {
        return {};
    }
    std::vector<std::string> result;
    std::string current;
    backtrack(digits, 0, current, result);
    return result;
}

int main() {
    const auto result = letterCombinations("23");
    std::cout << "count=" << result.size() << " (expected 9):";
    for (const std::string& s : result) {
        std::cout << " " << s;
    }
    std::cout << "\n";
    return 0;
}
