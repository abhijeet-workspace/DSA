// Surrounded Regions — https://leetcode.com/problems/surrounded-regions/
// Capture 'O' regions fully enclosed by 'X'; border-connected 'O's stay.
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<char>>& board, int r, int c) {
    if (r < 0 || r >= static_cast<int>(board.size()) || c < 0
        || c >= static_cast<int>(board[0].size()) || board[r][c] != 'O') {
        return;
    }
    board[r][c] = 'E'; // escaped — touches border
    dfs(board, r + 1, c);
    dfs(board, r - 1, c);
    dfs(board, r, c + 1);
    dfs(board, r, c - 1);
}

void solve(std::vector<std::vector<char>>& board) {
    if (board.empty() || board[0].empty()) {
        return;
    }
    const int m = static_cast<int>(board.size());
    const int n = static_cast<int>(board[0].size());

    for (int i = 0; i < m; ++i) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0);
        }
        if (board[i][n - 1] == 'O') {
            dfs(board, i, n - 1);
        }
    }
    for (int j = 0; j < n; ++j) {
        if (board[0][j] == 'O') {
            dfs(board, 0, j);
        }
        if (board[m - 1][j] == 'O') {
            dfs(board, m - 1, j);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X'; // surrounded
            } else if (board[i][j] == 'E') {
                board[i][j] = 'O'; // restore safe
            }
        }
    }
}

int main() {
    std::vector<std::vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    };
    solve(board);
    for (const auto& row : board) {
        for (char x : row) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
    // expected: only bottom-border O remains; inner OOO flipped to X
    return 0;
}
