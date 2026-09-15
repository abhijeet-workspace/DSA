// Expression Add Operators — https://leetcode.com/problems/expression-add-operators/
// Insert +, -, * between digits of num so expression equals target; return all expressions.
#include <iostream>
#include <string>
#include <vector>

void dfs(const std::string& num, int target, int pos, long curVal, long last, std::string expr,
         std::vector<std::string>& result) {
    if (pos == static_cast<int>(num.size())) {
        if (curVal == target) result.push_back(expr);
        return;
    }
    long val = 0;
    std::string piece;
    for (int i = pos; i < static_cast<int>(num.size()); ++i) {
        if (i > pos && num[static_cast<size_t>(pos)] == '0') break; // no leading zero
        val = val * 10 + (num[static_cast<size_t>(i)] - '0');
        piece.push_back(num[static_cast<size_t>(i)]);
        if (pos == 0) {
            dfs(num, target, i + 1, val, val, piece, result);
        } else {
            dfs(num, target, i + 1, curVal + val, val, expr + "+" + piece, result);
            dfs(num, target, i + 1, curVal - val, -val, expr + "-" + piece, result);
            dfs(num, target, i + 1, curVal - last + last * val, last * val, expr + "*" + piece, result);
        }
    }
}

std::vector<std::string> addOperators(const std::string& num, int target) {
    std::vector<std::string> result;
    dfs(num, target, 0, 0, 0, "", result);
    return result;
}

int main() {
    const auto r = addOperators("123", 6);
    std::cout << "count=" << r.size() << " (expected 2)\n";
    for (const auto& e : r) std::cout << e << "\n";
    return 0;
}
