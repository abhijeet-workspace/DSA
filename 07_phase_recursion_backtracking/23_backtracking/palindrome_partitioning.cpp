// Palindrome Partitioning — https://leetcode.com/problems/palindrome-partitioning/
// Partition s so every substring is a palindrome; return all partitions.
#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string& s, int l, int r) {
    while (l < r) {
        if (s[static_cast<size_t>(l++)] != s[static_cast<size_t>(r--)]) return false;
    }
    return true;
}

void backtrack(const std::string& s, int start, std::vector<std::string>& current,
               std::vector<std::vector<std::string>>& result) {
    if (start == static_cast<int>(s.size())) { // used whole string
        result.push_back(current);
        return;
    }
    for (int i = start; i < static_cast<int>(s.size()); ++i) {
        if (!isPalindrome(s, start, i)) continue;
        current.push_back(s.substr(static_cast<size_t>(start),
                                   static_cast<size_t>(i - start + 1))); // take cut
        backtrack(s, i + 1, current, result);
        current.pop_back(); // undo cut
    }
}

std::vector<std::vector<std::string>> partition(const std::string& s) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> current;
    backtrack(s, 0, current, result);
    return result;
}

int main() {
    const std::string s = "aab";
    const auto result = partition(s);
    std::cout << "Partitions of \"" << s << "\" (" << result.size()
              << " expected 2):\n";
    for (const auto& row : result) {
        std::cout << "[ ";
        for (const auto& part : row) std::cout << "\"" << part << "\" ";
        std::cout << "]\n";
    }
    return 0;
}
