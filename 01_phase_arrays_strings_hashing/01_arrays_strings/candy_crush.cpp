// Candy Crush — https://leetcode.com/problems/candy-crush/
// Crush 3+ equal candies in a row/col repeatedly; gravity drops remaining candies.
#include <cmath>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> candyCrush(std::vector<std::vector<int>> board) {
    const int m = static_cast<int>(board.size());
    const int n = static_cast<int>(board[0].size());
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                const int v = std::abs(board[static_cast<size_t>(i)][static_cast<size_t>(j)]);
                if (v == 0)
                    continue;
                if (j + 2 < n &&
                    std::abs(board[static_cast<size_t>(i)][static_cast<size_t>(j + 1)]) == v &&
                    std::abs(board[static_cast<size_t>(i)][static_cast<size_t>(j + 2)]) == v) {
                    changed = true;
                    board[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                        board[static_cast<size_t>(i)][static_cast<size_t>(j + 1)] =
                            board[static_cast<size_t>(i)][static_cast<size_t>(j + 2)] = -v;
                }
                if (i + 2 < m &&
                    std::abs(board[static_cast<size_t>(i + 1)][static_cast<size_t>(j)]) == v &&
                    std::abs(board[static_cast<size_t>(i + 2)][static_cast<size_t>(j)]) == v) {
                    changed = true;
                    board[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                        board[static_cast<size_t>(i + 1)][static_cast<size_t>(j)] =
                            board[static_cast<size_t>(i + 2)][static_cast<size_t>(j)] = -v;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            int write = m - 1;
            for (int i = m - 1; i >= 0; --i) {
                if (board[static_cast<size_t>(i)][static_cast<size_t>(j)] > 0) {
                    board[static_cast<size_t>(write--)][static_cast<size_t>(j)] =
                        board[static_cast<size_t>(i)][static_cast<size_t>(j)];
                }
            }
            while (write >= 0) {
                board[static_cast<size_t>(write--)][static_cast<size_t>(j)] = 0;
            }
        }
    }
    return board;
}

int main() {
    // Simple board: bottom row 2,2,2 crushes; gravity drops.
    std::vector<std::vector<int>> board = {{1, 3, 5, 7}, {2, 2, 2, 4}, {1, 1, 1, 8}};
    const auto out = candyCrush(board);
    for (const auto& row : out) {
        for (size_t j = 0; j < row.size(); ++j) {
            if (j)
                std::cout << ' ';
            std::cout << row[j];
        }
        std::cout << '\n';
    }
    std::cout << "(expected 0 0 0 7 / 0 0 0 4 / 1 3 5 8)\n";
    return 0;
}
