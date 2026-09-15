// Count Square Submatrices with All Ones —
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
#include <algorithm>
#include <iostream>
#include <vector>

int countSquares(std::vector<std::vector<int>>& matrix) {
    const int m = static_cast<int>(matrix.size());
    const int n = static_cast<int>(matrix[0].size());
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[static_cast<size_t>(i)][static_cast<size_t>(j)] && i && j) {
                matrix[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    1 + std::min({matrix[static_cast<size_t>(i - 1)][static_cast<size_t>(j)],
                                  matrix[static_cast<size_t>(i)][static_cast<size_t>(j - 1)],
                                  matrix[static_cast<size_t>(i - 1)][static_cast<size_t>(j - 1)]});
            }
            ans += matrix[static_cast<size_t>(i)][static_cast<size_t>(j)];
        }
    }
    return ans;
}

int main() {
    std::vector<std::vector<int>> m{{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    std::cout << countSquares(m) << " (expected 15)\n";
    return 0;
}
