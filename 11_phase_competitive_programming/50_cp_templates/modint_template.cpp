// Modint template — modular arithmetic struct (MOD = 1e9+7)
#include <iostream>

struct Mint {
    static constexpr int MOD = 1'000'000'007;
    int v;
    Mint(long long x = 0) : v(int((x % MOD + MOD) % MOD)) {}
    Mint& operator+=(Mint o) {
        v += o.v;
        if (v >= MOD)
            v -= MOD;
        return *this;
    }
    Mint& operator-=(Mint o) {
        v -= o.v;
        if (v < 0)
            v += MOD;
        return *this;
    }
    Mint& operator*=(Mint o) {
        v = int(1LL * v * o.v % MOD);
        return *this;
    }
    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return a *= b; }
};

int main() {
    Mint a = 1'000'000'006; // -1
    Mint b = 3;
    Mint c = a + b; // 2
    Mint d = a * b; // (MOD-1)*3 % MOD
    std::cout << "c=" << c.v << " d=" << d.v << "\n";
    const bool ok = (c.v == 2 && d.v == 1'000'000'004);
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
