// Lucas theorem demo — teaching
#include <iostream>
long long modpow(long long a, long long e, long long mod) {
    long long r = 1 % mod;
    while (e) {
        if (e & 1)
            r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}
long long nCrMod(long long n, long long r, int p) {
    if (r < 0 || r > n)
        return 0;
    long long num = 1, den = 1;
    for (long long i = 0; i < r; ++i) {
        num = num * ((n - i) % p) % p;
        den = den * ((i + 1) % p) % p;
    }
    return num * modpow(den, p - 2, p) % p;
}
long long lucas(long long n, long long r, int p) {
    if (r < 0)
        return 0;
    long long ans = 1;
    while (n > 0 || r > 0) {
        long long ni = n % p, ri = r % p;
        if (ri > ni)
            return 0;
        ans = ans * nCrMod(ni, ri, p) % p;
        n /= p;
        r /= p;
    }
    return ans;
}
int main() {
    std::cout << lucas(10, 3, 5) << " (expected 0)\n";
    std::cout << lucas(5, 2, 5) << " (expected 10%5=0)\n";
    std::cout << lucas(6, 2, 5) << " (expected 15%5=0)\n";
    std::cout << lucas(4, 2, 5) << " (expected 6%5=1)\n";
    return 0;
}
