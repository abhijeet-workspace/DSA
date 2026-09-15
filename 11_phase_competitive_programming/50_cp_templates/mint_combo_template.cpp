// Mint + factorials template — nCr mod 1e9+7
#include <iostream>
#include <vector>

struct Mint {
    static constexpr int MOD = 1'000'000'007;
    int v;
    Mint(long long x = 0) : v(int((x % MOD + MOD) % MOD)) {}
    Mint& operator*=(Mint o) {
        v = int(1LL * v * o.v % MOD);
        return *this;
    }
    friend Mint operator*(Mint a, Mint b) { return a *= b; }
    Mint pow(long long e) const {
        Mint base = *this, ans = 1;
        while (e) {
            if (e & 1)
                ans *= base;
            base *= base;
            e >>= 1;
        }
        return ans;
    }
    Mint inv() const { return pow(MOD - 2); }
};

struct Comb {
    std::vector<Mint> fact, ifact;
    explicit Comb(int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * Mint(i);
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i)
            ifact[i - 1] = ifact[i] * Mint(i);
    }
    Mint C(int n, int k) const {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

int main() {
    Comb comb(20);
    const int v = comb.C(10, 3).v; // 120
    std::cout << "C(10,3)=" << v << " expected=120\n";
    std::cout << (v == 120 ? "OK\n" : "FAIL\n");
    return v == 120 ? 0 : 1;
}
