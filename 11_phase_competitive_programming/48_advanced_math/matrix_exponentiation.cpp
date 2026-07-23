// Matrix exponentiation — Fibonacci via 2×2 transition^n
// Time O(D^3 log n) with D=2; space O(D^2)
#include <iostream>
#include <vector>

using ll = long long;
constexpr int MOD = 1'000'000'007;
using Matrix = std::vector<std::vector<ll>>;

Matrix multiply(const Matrix& A, const Matrix& B) {
    const int r = static_cast<int>(A.size());
    const int c = static_cast<int>(A[0].size());
    const int c2 = static_cast<int>(B[0].size());
    Matrix C(r, std::vector<ll>(c2, 0));
    for (int i = 0; i < r; ++i) {
        for (int k = 0; k < c; ++k) {
            for (int j = 0; j < c2; ++j) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, ll exp) {
    const int n = static_cast<int>(A.size());
    Matrix res(n, std::vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) res[i][i] = 1; // identity
    while (exp > 0) {
        if (exp & 1) res = multiply(res, A);
        A = multiply(A, A);
        exp >>= 1;
    }
    return res;
}

ll fibonacci(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    Matrix T = {{1, 1}, {1, 0}};
    T = power(T, n - 1);
    return T[0][0]; // F_n
}

int main() {
    std::cout << "Fibonacci(10)=" << fibonacci(10) << " (expected 55)\n";
    std::cout << "Fibonacci(50)=" << fibonacci(50) << "\n";
    return 0;
}
