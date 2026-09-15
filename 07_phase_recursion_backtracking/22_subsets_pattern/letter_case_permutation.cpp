// Letter Case Permutation — https://leetcode.com/problems/letter-case-permutation/
// Return all strings formed by toggling case of letters in s (digits fixed).
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

void dfs(std::string& s, int i, std::vector<std::string>& result) {
    if (i == static_cast<int>(s.size())) {
        result.push_back(s);
        return;
    }
    if (std::isdigit(static_cast<unsigned char>(s[static_cast<size_t>(i)]))) {
        dfs(s, i + 1, result);
        return;
    }
    s[static_cast<size_t>(i)] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[static_cast<size_t>(i)])));
    dfs(s, i + 1, result);
    s[static_cast<size_t>(i)] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[static_cast<size_t>(i)])));
    dfs(s, i + 1, result);
}

std::vector<std::string> letterCasePermutation(std::string s) {
    std::vector<std::string> result;
    dfs(s, 0, result);
    return result;
}

int main() {
    const auto r = letterCasePermutation("a1b2");
    std::cout << "count=" << r.size() << " (expected 4)\n";
    for (const auto& x : r) std::cout << x << "\n";
    return 0;
}
