// Teaching lab: modular inverse via Fermat (prime mod)
#include <iostream>

long long modPow(long long a, long long e, long long mod) {
    long long r = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1)
            r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}

long long modInverseFermat(long long a, long long p) {
    a %= p;
    if (a < 0)
        a += p;
    if (a == 0)
        return -1; // non-invertible
    return modPow(a, p - 2, p);
}

int main() {
    std::cout << "inv(3) mod 11=" << modInverseFermat(3, 11) << " (expected 4)\n";
    std::cout << "check 3*4%11=" << (3 * 4 % 11) << " (expected 1)\n";
    return 0;
}
