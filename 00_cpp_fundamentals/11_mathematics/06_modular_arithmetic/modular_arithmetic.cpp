// Modular Arithmetic — C++ fundamentals
// Mod normalize, add/mul, modpow, inverse via ExtGcd.
#include <iostream>

long long modNorm(long long a, long long m) {
    return ((a % m) + m) % m;
}

long long modAdd(long long a, long long b, long long m) {
    return modNorm(modNorm(a, m) + modNorm(b, m), m);
}

long long modSub(long long a, long long b, long long m) {
    return modNorm(modNorm(a, m) - modNorm(b, m), m);
}

long long modMul(long long a, long long b, long long m) {
    a = modNorm(a, m);
    b = modNorm(b, m);
#if defined(__SIZEOF_INT128__)
    return static_cast<long long>((__int128)a * b % m);
#else
    long long res = 0;
    while (b > 0) {
        if (b & 1) {
            res = (res + a) % m;
        }
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
#endif
}

long long modPow(long long base, long long exp, long long m) {
    long long ans = 1 % m;
    base = modNorm(base, m);
    while (exp > 0) {
        if (exp & 1) {
            ans = modMul(ans, base, m);
        }
        base = modMul(base, base, m);
        exp >>= 1;
    }
    return ans;
}

long long extGcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1 = 0, y1 = 0;
    long long g = extGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Returns -1 if inverse does not exist.
long long modInverse(long long a, long long m) {
    long long x = 0, y = 0;
    long long g = extGcd(modNorm(a, m), m, x, y);
    if (g != 1) {
        return -1;
    }
    return modNorm(x, m);
}

int main() {
    std::cout << "modAdd(7,8,5) = " << modAdd(7, 8, 5) << " (expected 0)\n";
    std::cout << "modSub(2,5,7) = " << modSub(2, 5, 7) << " (expected 4)\n";
    std::cout << "modPow(3,5,7) = " << modPow(3, 5, 7) << " (expected 5)\n";
    std::cout << "inv(3) mod 11 = " << modInverse(3, 11) << " (expected 4)\n";
    std::cout << "inv(2) mod 4 = " << modInverse(2, 4) << " (expected -1)\n";
    return 0;
}
