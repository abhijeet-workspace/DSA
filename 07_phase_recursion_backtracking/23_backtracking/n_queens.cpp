// N-Queens — https://leetcode.com/problems/n-queens/
// Place n queens so no two share row, column, or diagonal; return all boards.
#include <iostream>
#include <string>
#include <vector>

bool isValid(const std::vector<std::string>& board, int row, int col, int n) {
    for (int i = 0; i < row; ++i) { // same column
        if (board[static_cast<size_t>(i)][static_cast<size_t>(col)] == 'Q') return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) { // left diag
        if (board[static_cast<size_t>(i)][static_cast<size_t>(j)] == 'Q') return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) { // right diag
        if (board[static_cast<size_t>(i)][static_cast<size_t>(j)] == 'Q') return false;
    }
    return true;
}

void solve(std::vector<std::string>& board, int row, int n,
           std::vector<std::vector<std::string>>& result) {
    if (row == n) { // one full placement
        result.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (!isValid(board, row, col, n)) continue;
        board[static_cast<size_t>(row)][static_cast<size_t>(col)] = 'Q'; // place
        solve(board, row + 1, n, result);
        board[static_cast<size_t>(row)][static_cast<size_t>(col)] = '.'; // backtrack
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> board(static_cast<size_t>(n), std::string(static_cast<size_t>(n), '.'));
    solve(board, 0, n, result);
    return result;
}

int main() {
    const int n = 4;
    const auto boards = solveNQueens(n);
    std::cout << "Found " << boards.size() << " solutions for " << n
              << "-Queens (expected 2)\n";
    for (size_t i = 0; i < boards.size(); ++i) {
        std::cout << "Solution " << (i + 1) << ":\n";
        for (const auto& row : boards[i]) {
            std::cout << "  " << row << "\n";
        }
    }
    return 0;
}
