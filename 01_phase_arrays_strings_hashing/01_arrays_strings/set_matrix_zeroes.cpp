// Set Matrix Zeroes — https://leetcode.com/problems/set-matrix-zeroes/
// If an element is 0, set its entire row and column to 0 (in-place).
#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& a) {
    const int m = static_cast<int>(a.size());
    const int n = static_cast<int>(a[0].size());
    bool firstCol = false; // whether col 0 must be zeroed
    for (int i = 0; i < m; ++i) {
        if (a[static_cast<size_t>(i)][0] == 0) firstCol = true;
        for (int j = 1; j < n; ++j) {
            if (a[static_cast<size_t>(i)][static_cast<size_t>(j)] == 0) {
                a[static_cast<size_t>(i)][0] = 0; // mark row
                a[0][static_cast<size_t>(j)] = 0; // mark col
            }
        }
    }
    for (int i = 1; i < m; ++i) { // apply markers (skip first row/col)
        for (int j = 1; j < n; ++j) {
            if (a[static_cast<size_t>(i)][0] == 0 || a[0][static_cast<size_t>(j)] == 0) {
                a[static_cast<size_t>(i)][static_cast<size_t>(j)] = 0;
            }
        }
    }
    if (a[0][0] == 0) { // zero first row from its marker
        for (int j = 0; j < n; ++j) a[0][static_cast<size_t>(j)] = 0;
    }
    if (firstCol) { // zero first column last
        for (int i = 0; i < m; ++i) a[static_cast<size_t>(i)][0] = 0;
    }
}

int main() {
    std::vector<std::vector<int>> a = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(a);
    for (const auto& r : a) {
        for (int x : r) std::cout << x << " ";
        std::cout << "\n";
    }
    // expected: 1 0 1 / 0 0 0 / 1 0 1
    return 0;
}
