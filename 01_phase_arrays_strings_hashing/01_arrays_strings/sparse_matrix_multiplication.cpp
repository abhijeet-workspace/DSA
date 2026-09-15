// Sparse Matrix Multiplication — https://leetcode.com/problems/sparse-matrix-multiplication/
// Multiply two sparse matrices A (m×k) and B (k×n) efficiently by skipping zeros.
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::vector<int>> multiply(const std::vector<std::vector<int>>& A,
                                       const std::vector<std::vector<int>>& B) {
    const int m = static_cast<int>(A.size());
    const int k = static_cast<int>(A[0].size());
    const int n = static_cast<int>(B[0].size());
    std::vector<std::vector<std::pair<int, int>>> bSparse(static_cast<size_t>(k));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (B[static_cast<size_t>(i)][static_cast<size_t>(j)] != 0) {
                bSparse[static_cast<size_t>(i)].push_back(
                    {j, B[static_cast<size_t>(i)][static_cast<size_t>(j)]});
            }
        }
    }
    std::vector<std::vector<int>> C(static_cast<size_t>(m),
                                    std::vector<int>(static_cast<size_t>(n), 0));
    for (int i = 0; i < m; ++i) {
        for (int t = 0; t < k; ++t) {
            if (A[static_cast<size_t>(i)][static_cast<size_t>(t)] == 0) {
                continue;
            }
            for (const auto& [j, bv] : bSparse[static_cast<size_t>(t)]) {
                C[static_cast<size_t>(i)][static_cast<size_t>(j)] +=
                    A[static_cast<size_t>(i)][static_cast<size_t>(t)] * bv;
            }
        }
    }
    return C;
}

int main() {
    const std::vector<std::vector<int>> A = {{1, 0, 0}, {-1, 0, 3}};
    const std::vector<std::vector<int>> B = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    const auto C = multiply(A, B);
    // expected [[7,0,0],[-7,0,3]]
    for (const auto& row : C) {
        for (size_t j = 0; j < row.size(); ++j) {
            if (j)
                std::cout << ' ';
            std::cout << row[j];
        }
        std::cout << '\n';
    }
    std::cout << "(expected 7 0 0 / -7 0 3)\n";
    return 0;
}
