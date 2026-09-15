// N-Queens II — https://leetcode.com/problems/n-queens-ii/
// Return the number of distinct solutions to the n-queens puzzle.
#include <iostream>
#include <vector>

void solve(int row, int n, std::vector<bool>& col, std::vector<bool>& d1, std::vector<bool>& d2,
           int& count) {
    if (row == n) {
        ++count;
        return;
    }
    for (int c = 0; c < n; ++c) {
        if (col[static_cast<size_t>(c)] || d1[static_cast<size_t>(row - c + n - 1)] ||
            d2[static_cast<size_t>(row + c)])
            continue;
        col[static_cast<size_t>(c)] = d1[static_cast<size_t>(row - c + n - 1)] =
            d2[static_cast<size_t>(row + c)] = true;
        solve(row + 1, n, col, d1, d2, count);
        col[static_cast<size_t>(c)] = d1[static_cast<size_t>(row - c + n - 1)] =
            d2[static_cast<size_t>(row + c)] = false;
    }
}

int totalNQueens(int n) {
    std::vector<bool> col(static_cast<size_t>(n), false);
    std::vector<bool> d1(static_cast<size_t>(2 * n - 1), false);
    std::vector<bool> d2(static_cast<size_t>(2 * n - 1), false);
    int count = 0;
    solve(0, n, col, d1, d2, count);
    return count;
}

int main() {
    std::cout << totalNQueens(4) << " (expected 2)\n";
    std::cout << totalNQueens(1) << " (expected 1)\n";
    return 0;
}
