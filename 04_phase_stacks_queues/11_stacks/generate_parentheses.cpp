// Generate Parentheses — https://leetcode.com/problems/generate-parentheses/
// Backtrack: add '(' if open<n; add ')' if close<open.
#include <iostream>
#include <string>
#include <vector>

static void dfs(int open, int close, int n, std::string& cur,
                std::vector<std::string>& out) {
    if (static_cast<int>(cur.size()) == 2 * n) {
        out.push_back(cur);
        return;
    }
    if (open < n) {
        cur.push_back('(');
        dfs(open + 1, close, n, cur, out);
        cur.pop_back(); // backtrack
    }
    if (close < open) {
        cur.push_back(')');
        dfs(open, close + 1, n, cur, out);
        cur.pop_back();
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> out;
    std::string cur;
    dfs(0, 0, n, cur, out);
    return out;
}

int main() {
    for (const auto& s : generateParenthesis(3)) {
        std::cout << s << ' ';
    }
    std::cout << '\n';
    return 0;
}
