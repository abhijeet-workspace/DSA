// Generate Parentheses — https://leetcode.com/problems/generate-parentheses/
// Generate all combinations of n pairs of well-formed parentheses.
#include <iostream>
#include <string>
#include <vector>

void dfs(int open, int close, int n, std::string& cur, std::vector<std::string>& result) {
    if (static_cast<int>(cur.size()) == 2 * n) {
        result.push_back(cur);
        return;
    }
    if (open < n) {
        cur.push_back('(');
        dfs(open + 1, close, n, cur, result);
        cur.pop_back();
    }
    if (close < open) {
        cur.push_back(')');
        dfs(open, close + 1, n, cur, result);
        cur.pop_back();
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    std::string cur;
    dfs(0, 0, n, cur, result);
    return result;
}

int main() {
    const auto r = generateParenthesis(3);
    std::cout << "count=" << r.size() << " (expected 5)\n";
    for (const auto& s : r) std::cout << s << "\n";
    return 0;
}
