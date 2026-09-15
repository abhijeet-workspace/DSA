// Reshape the Matrix — LC 566
// Flat index k maps to (k/c, k%c) in the new matrix if r*c == m*n.
#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrixReshape(const std::vector<std::vector<int>>& mat, int r, int c) {
    const int m = static_cast<int>(mat.size());
    const int n = static_cast<int>(mat[0].size());
    if (m * n != r * c) return mat;

    std::vector<std::vector<int>> ans(static_cast<size_t>(r), std::vector<int>(static_cast<size_t>(c)));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            const int k = i * n + j;
            ans[static_cast<size_t>(k / c)][static_cast<size_t>(k % c)] = mat[static_cast<size_t>(i)][static_cast<size_t>(j)];
        }
    }
    return ans;
}

int main() {
    auto ans = matrixReshape({{1, 2}, {3, 4}}, 1, 4);
    for (const auto& row : ans) {
        for (int x : row) std::cout << x << " ";
        std::cout << "\n";
    }
    // expected: 1 2 3 4
    return 0;
}
