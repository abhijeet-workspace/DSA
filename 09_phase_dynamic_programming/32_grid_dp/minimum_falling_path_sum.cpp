// Minimum Falling Path Sum — https://leetcode.com/problems/minimum-falling-path-sum/
#include <algorithm>
#include <iostream>
#include <vector>

int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
    const int n = static_cast<int>(matrix.size());
    for (int r = n - 2; r >= 0; --r) {
        for (int c = 0; c < n; ++c) {
            int best = matrix[static_cast<size_t>(r + 1)][static_cast<size_t>(c)];
            if (c > 0)
                best =
                    std::min(best, matrix[static_cast<size_t>(r + 1)][static_cast<size_t>(c - 1)]);
            if (c + 1 < n)
                best =
                    std::min(best, matrix[static_cast<size_t>(r + 1)][static_cast<size_t>(c + 1)]);
            matrix[static_cast<size_t>(r)][static_cast<size_t>(c)] += best;
        }
    }
    return *std::min_element(matrix[0].begin(), matrix[0].end());
}

int main() {
    std::vector<std::vector<int>> m{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    std::cout << minFallingPathSum(m) << " (expected 13)\n";
    return 0;
}
