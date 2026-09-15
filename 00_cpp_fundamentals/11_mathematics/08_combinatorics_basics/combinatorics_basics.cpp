// Combinatorics Basics — C++ fundamentals
// nPr, multiplicative nCr, Pascal triangle row.
#include <algorithm>
#include <iostream>
#include <vector>

long long gcdLL(long long a, long long b) {
    return b == 0 ? a : gcdLL(b, a % b);
}

long long nPr(int n, int r) {
    if (r < 0 || n < 0 || r > n) {
        return 0;
    }
    long long ans = 1;
    for (int i = 0; i < r; ++i) {
        ans *= (n - i);
    }
    return ans;
}

long long nCr(int n, int r) {
    if (r < 0 || n < 0 || r > n) {
        return 0;
    }
    r = std::min(r, n - r);
    long long ans = 1;
    for (int i = 1; i <= r; ++i) {
        long long num = n - r + i;
        long long den = i;
        long long g = gcdLL(num, den);
        num /= g;
        den /= g;
        g = gcdLL(ans, den);
        ans /= g;
        den /= g;
        ans *= num;
        ans /= den;
    }
    return ans;
}

std::vector<long long> pascalRow(int n) {
    std::vector<long long> row(static_cast<size_t>(n) + 1, 0);
    row[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j >= 1; --j) {
            row[static_cast<size_t>(j)] += row[static_cast<size_t>(j) - 1];
        }
    }
    return row;
}

int main() {
    std::cout << "P(5,2) = " << nPr(5, 2) << " (expected 20)\n";
    std::cout << "C(5,2) = " << nCr(5, 2) << " (expected 10)\n";
    std::cout << "C(10,3) = " << nCr(10, 3) << " (expected 120)\n";

    auto row = pascalRow(4);
    std::cout << "Pascal row 4:";
    for (long long x : row) {
        std::cout << " " << x;
    }
    std::cout << " (expected 1 4 6 4 1)\n";
    return 0;
}
