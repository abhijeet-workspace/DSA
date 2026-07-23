// Monte Carlo primality — Fermat witnesses demo
// Random bases; composites often fail; Carmichael can fool Fermat.
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>

long long mod_pow(long long a, long long e, long long mod) {
    long long r = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1) {
            r = static_cast<__int128>(r) * a % mod;
        }
        a = static_cast<__int128>(a) * a % mod;
        e >>= 1;
    }
    return r;
}

bool fermat_probable_prime(long long n, int rounds) {
    if (n < 2) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 0; i < rounds; ++i) {
        const long long a = 2 + std::rand() % (n - 3);
        if (mod_pow(a, n - 1, n) != 1) {
            return false; // definitely composite
        }
    }
    return true; // probably prime
}

int main() {
    std::srand(7);
    std::cout << "97 prime? " << (fermat_probable_prime(97, 5) ? "yes" : "no")
              << " (expected yes)\n";
    std::cout << "91 prime? " << (fermat_probable_prime(91, 8) ? "yes" : "no")
              << " (expected no usually)\n";
    return 0;
}
