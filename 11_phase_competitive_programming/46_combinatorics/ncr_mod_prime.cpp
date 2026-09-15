// nCr mod prime — teaching
#include <iostream>
#include <vector>
const long long MOD = 1000000007LL;
long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}
struct Comb {
    std::vector<long long> fact, invfact;
    Comb(int n) : fact(n + 1), invfact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invfact[n] = modpow(fact[n], MOD - 2);
        for (int i = n; i >= 1; --i)
            invfact[i - 1] = invfact[i] * i % MOD;
    }
    long long C(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    }
};
int main() {
    Comb cb(100);
    std::cout << cb.C(5, 2) << " (expected 10)\n";
    return 0;
}
