// 2D Prefix Sum — https://leetcode.com/problems/range-sum-query-2d-immutable/
// Preprocess matrix so any subrectangle sum answers in O(1).
#include <iostream>
#include <vector>

class PrefixSum2D {
    std::vector<std::vector<int>> prefix; // prefix[r][c] = sum of matrix[0..r-1][0..c-1]
public:
    explicit PrefixSum2D(const std::vector<std::vector<int>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        prefix.assign(rows + 1, std::vector<int>(cols + 1, 0));
        for (int r = 1; r <= rows; ++r) {
            for (int c = 1; c <= cols; ++c) {
                prefix[r][c] = matrix[r - 1][c - 1]
                             + prefix[r - 1][c]
                             + prefix[r][c - 1]
                             - prefix[r - 1][c - 1]; // inclusion-exclusion build
            }
        }
    }

    int query(int r1, int c1, int r2, int c2) const {
        return prefix[r2 + 1][c2 + 1]
             - prefix[r1][c2 + 1]
             - prefix[r2 + 1][c1]
             + prefix[r1][c1]; // IE: subtract left/above, add corner back
    }
};

int main() {
    PrefixSum2D ps2d({{3, 0, 1, 4}, {5, 6, 3, 2}, {1, 2, 0, 1}, {5, 8, 7, 9}});
    std::cout << ps2d.query(2, 1, 3, 2) << " (expected 17)\n";
    return 0;
}
