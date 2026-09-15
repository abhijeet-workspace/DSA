#include <iostream>
#include <vector>
constexpr int MOD = 1'000'000'007;
int modPow(long long a, long long e) {
    long long r = 1;
    a %= MOD;
    while (e) {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return (int)r;
}
std::vector<int> solve(std::vector<std::vector<int>> a) {
    int n = a.size();
    for (int col = 0; col < n; ++col) {
        int piv = col;
        while (piv < n && a[piv][col] == 0)
            ++piv;
        if (piv == n)
            continue;
        std::swap(a[col], a[piv]);
        int inv = modPow(a[col][col], MOD - 2);
        for (int j = col; j <= n; ++j)
            a[col][j] = (int)(1LL * a[col][j] * inv % MOD);
        for (int i = 0; i < n; ++i)
            if (i != col && a[i][col]) {
                int f = a[i][col];
                for (int j = col; j <= n; ++j) {
                    a[i][j] = (int)((a[i][j] - 1LL * f * a[col][j]) % MOD);
                    if (a[i][j] < 0)
                        a[i][j] += MOD;
                }
            }
    }
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i)
        x[i] = a[i][n];
    return x;
}
int main() {
    auto x = solve({{1, 1, 3}, {1, 2, 5}});
    std::cout << "x=" << x[0] << " y=" << x[1] << " (expected 1 2)\n";
    return 0;
}
