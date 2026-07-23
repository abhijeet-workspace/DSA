// Catalan Numbers — C(n) = C(2n,n)/(n+1) mod 1e9+7
// Factorials + Fermat inverses; related to Unique BSTs (LC 96).
#include <iostream>
#include <vector>

const long long MOD = 1000000007LL;

long long fastPow(long long base, long long exp, long long mod) {
    long long result = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

long long catalanNumber(int n) {
    std::vector<long long> fact(2 * n + 1), invFact(2 * n + 1);
    fact[0] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[2 * n] = fastPow(fact[2 * n], MOD - 2, MOD);
    for (int i = 2 * n - 1; i >= 0; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
    long long binom = fact[2 * n] * invFact[n] % MOD * invFact[n] % MOD;
    return binom * fastPow(n + 1, MOD - 2, MOD) % MOD;
}

int main() {
    std::cout << "Catalan:";
    for (int i = 0; i <= 8; ++i) {
        std::cout << " " << catalanNumber(i);
    }
    std::cout << " (expected 1 1 2 5 14 42 132 429 1430)\n";
    return 0;
}
