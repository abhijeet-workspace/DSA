// Valid Sudoku — LC 36
// Track seen digits per row, column, and 3×3 box with bitmasks.
#include <iostream>
#include <vector>

bool isValidSudoku(const std::vector<std::vector<char>>& board) {
    int rows[9] = {};
    int cols[9] = {};
    int boxes[9] = {};
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            char ch = board[static_cast<size_t>(r)][static_cast<size_t>(c)];
            if (ch == '.')
                continue;
            int bit = 1 << (ch - '1');
            int box = (r / 3) * 3 + (c / 3);
            if ((rows[r] & bit) || (cols[c] & bit) || (boxes[box] & bit))
                return false;
            rows[r] |= bit;
            cols[c] |= bit;
            boxes[box] |= bit;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> valid = {
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
    std::vector<std::vector<char>> invalid = valid;
    invalid[0][0] = '8'; // duplicates with invalid[3][0]
    std::cout << std::boolalpha << isValidSudoku(valid) << " (expected true)\n"
              << isValidSudoku(invalid) << " (expected false)\n";
    return 0;
}
