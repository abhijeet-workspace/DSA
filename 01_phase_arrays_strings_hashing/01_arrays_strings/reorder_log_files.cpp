// Reorder Data in Log Files — https://leetcode.com/problems/reorder-data-in-log-files/
// Letter-logs sorted by content then id; digit-logs keep relative order after letter-logs.
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::vector<std::string> reorderLogFiles(std::vector<std::string> logs) {
    auto isDigitLog = [](const std::string& log) {
        const auto sp = log.find(' ');
        return std::isdigit(static_cast<unsigned char>(log[sp + 1])) != 0;
    };
    std::vector<std::string> letter, digit;
    for (auto& log : logs) {
        if (isDigitLog(log)) {
            digit.push_back(std::move(log));
        } else {
            letter.push_back(std::move(log));
        }
    }
    auto key = [](const std::string& log) {
        const auto sp = log.find(' ');
        return std::make_pair(log.substr(sp + 1), log.substr(0, sp));
    };
    std::sort(letter.begin(), letter.end(),
              [&](const std::string& a, const std::string& b) { return key(a) < key(b); });
    letter.insert(letter.end(), digit.begin(), digit.end());
    return letter;
}

int main() {
    std::vector<std::string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig",
                                     "let3 art zero"};
    const auto out = reorderLogFiles(logs);
    for (const auto& s : out) {
        std::cout << s << '\n';
    }
    std::cout << "(expected let1, let3, let2, dig1, dig2)\n";
    return 0;
}
