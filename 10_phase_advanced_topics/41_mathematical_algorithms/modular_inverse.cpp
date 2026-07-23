// Modular inverse (+ modAdd / modMul) — Fermat a^(p-2) when p prime
#include <iostream>

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

long long modInverse(long long a, long long p) {
    return fastPow(a, p - 2, p); // Fermat: needs prime p, gcd(a,p)=1
}

long long modAdd(long long a, long long b, long long mod) {
    a %= mod;
    b %= mod;
    long long s = a + b;
    if (s >= mod) {
        s -= mod;
    }
    return s;
}

long long modMul(long long a, long long b, long long mod) {
    return static_cast<__int128>(a) * b % mod;
}

int main() {
    const long long MOD = 1000000007LL;
    std::cout << modInverse(3, 7) << " (expected 5)\n";
    std::cout << modAdd(998, 5, MOD) << " (expected 1003)\n";
    std::cout << modMul(1000000000LL, 1000000000LL, MOD) << " (expected 49)\n";
    return 0;
}
