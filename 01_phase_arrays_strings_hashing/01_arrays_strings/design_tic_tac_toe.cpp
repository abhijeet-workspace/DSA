// Design Tic-Tac-Toe — https://leetcode.com/problems/design-tic-tac-toe/
// n×n board; move returns winner (1/2) or 0. Track rows/cols/diags in O(1) per move.
#include <cstdlib>
#include <iostream>
#include <vector>

class TicTacToe {
    int n_;
    std::vector<int> rows_, cols_;
    int diag_ = 0;
    int anti_ = 0;

public:
    explicit TicTacToe(int n) : n_(n), rows_(static_cast<size_t>(n), 0), cols_(static_cast<size_t>(n), 0) {}

    int move(int row, int col, int player) {
        const int d = player == 1 ? 1 : -1;
        rows_[static_cast<size_t>(row)] += d;
        cols_[static_cast<size_t>(col)] += d;
        if (row == col) {
            diag_ += d;
        }
        if (row + col == n_ - 1) {
            anti_ += d;
        }
        if (std::abs(rows_[static_cast<size_t>(row)]) == n_ ||
            std::abs(cols_[static_cast<size_t>(col)]) == n_ ||
            std::abs(diag_) == n_ || std::abs(anti_) == n_) {
            return player;
        }
        return 0;
    }
};

int main() {
    TicTacToe toe(3);
    std::cout << toe.move(0, 0, 1) << " (expected 0)\n";
    std::cout << toe.move(0, 2, 2) << " (expected 0)\n";
    std::cout << toe.move(2, 2, 1) << " (expected 0)\n";
    std::cout << toe.move(1, 1, 2) << " (expected 0)\n";
    std::cout << toe.move(2, 0, 1) << " (expected 0)\n";
    std::cout << toe.move(1, 0, 2) << " (expected 0)\n";
    std::cout << toe.move(2, 1, 1) << " (expected 1)\n";
    return 0;
}
