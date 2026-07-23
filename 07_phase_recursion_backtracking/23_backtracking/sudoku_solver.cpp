// Sudoku Solver — https://leetcode.com/problems/sudoku-solver/
// Fill '.' cells so each row, column, and 3x3 box has digits 1-9 once.
#include <iostream>
#include <vector>

bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; ++i) {
        if (board[static_cast<size_t>(i)][static_cast<size_t>(col)] == c) return false; // col
        if (board[static_cast<size_t>(row)][static_cast<size_t>(i)] == c) return false; // row
        const int br = 3 * (row / 3) + i / 3;
        const int bc = 3 * (col / 3) + i % 3;
        if (board[static_cast<size_t>(br)][static_cast<size_t>(bc)] == c) return false; // box
    }
    return true;
}

bool solve(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[static_cast<size_t>(i)][static_cast<size_t>(j)] != '.') continue;
            for (char c = '1'; c <= '9'; ++c) {
                if (!isValid(board, i, j, c)) continue;
                board[static_cast<size_t>(i)][static_cast<size_t>(j)] = c; // try
                if (solve(board)) return true;
                board[static_cast<size_t>(i)][static_cast<size_t>(j)] = '.'; // undo
            }
            return false; // no digit works here
        }
    }
    return true; // no empty cells left
}

void solveSudoku(std::vector<std::vector<char>>& board) {
    solve(board);
}

int main() {
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    solveSudoku(board);
    std::cout << "Solved board (row0 expected 5 3 4 6 7 8 9 1 2):\n";
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            std::cout << board[static_cast<size_t>(r)][static_cast<size_t>(c)] << ' ';
        }
        std::cout << "\n";
    }
    return 0;
}
