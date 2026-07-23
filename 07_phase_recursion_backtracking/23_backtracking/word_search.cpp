// Word Search — https://leetcode.com/problems/word-search/
// Return true if word exists via 4-dir adjacent cells without reuse.
#include <iostream>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<char>>& board, int r, int c,
         const std::string& word, int i) {
    if (i == static_cast<int>(word.size())) return true; // matched all
    if (r < 0 || c < 0 || r >= static_cast<int>(board.size())
        || c >= static_cast<int>(board[0].size())
        || board[static_cast<size_t>(r)][static_cast<size_t>(c)]
               != word[static_cast<size_t>(i)]) {
        return false;
    }
    const char tmp = board[static_cast<size_t>(r)][static_cast<size_t>(c)];
    board[static_cast<size_t>(r)][static_cast<size_t>(c)] = '#'; // mark visited
    const bool found = dfs(board, r + 1, c, word, i + 1)
        || dfs(board, r - 1, c, word, i + 1)
        || dfs(board, r, c + 1, word, i + 1)
        || dfs(board, r, c - 1, word, i + 1);
    board[static_cast<size_t>(r)][static_cast<size_t>(c)] = tmp; // restore
    return found;
}

bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
    for (int i = 0; i < static_cast<int>(board.size()); ++i) {
        for (int j = 0; j < static_cast<int>(board[0].size()); ++j) {
            if (dfs(board, i, j, word, 0)) return true;
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    std::cout << std::boolalpha << exist(board, "ABCCED")
              << " (expected true)\n";
    return 0;
}
