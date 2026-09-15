#include <algorithm>
#include <iostream>
#include <vector>
constexpr int MOD = 998244353;
int modPow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return (int)r;
}
void ntt(std::vector<int>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            std::swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = modPow(3, (MOD - 1) / len);
        if (invert)
            wlen = modPow(wlen, MOD - 2);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % MOD);
                a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                w = (int)(1LL * w * wlen % MOD);
            }
        }
    }
    if (invert) {
        int invn = modPow(n, MOD - 2);
        for (int& x : a)
            x = (int)(1LL * x * invn % MOD);
    }
}
std::vector<int> multiply(std::vector<int> a, std::vector<int> b) {
    int n = 1;
    while (n < (int)(a.size() + b.size()))
        n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; ++i)
        a[i] = (int)(1LL * a[i] * b[i] % MOD);
    ntt(a, true);
    while (!a.empty() && a.back() == 0)
        a.pop_back();
    return a;
}
int main() {
    auto c = multiply({1, 2}, {3, 4});
    std::cout << "ntt:";
    for (int x : c)
        std::cout << " " << x;
    std::cout << " (expected 3 10 8)\n";
    return 0;
}
