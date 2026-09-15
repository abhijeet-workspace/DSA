// Miller-Rabin deterministic lab — 32-bit witnesses 2,7,61
#include <cstdint>
#include <iostream>

uint64_t mod_mul(uint64_t a, uint64_t b, uint64_t mod) {
    return (__uint128_t)a * b % mod;
}
uint64_t mod_pow(uint64_t a, uint64_t e, uint64_t mod) {
    uint64_t r = 1;
    while (e) {
        if (e & 1)
            r = mod_mul(r, a, mod);
        a = mod_mul(a, a, mod);
        e >>= 1;
    }
    return r;
}
bool check(uint64_t n, uint64_t a, uint64_t d, int s) {
    uint64_t x = mod_pow(a % n, d, n);
    if (x == 1 || x == n - 1)
        return true;
    for (int r = 1; r < s; ++r) {
        x = mod_mul(x, x, n);
        if (x == n - 1)
            return true;
    }
    return false;
}
bool isPrime(uint32_t n) {
    if (n < 2)
        return false;
    for (uint32_t p : {2u, 3u, 5u, 7u, 11u}) {
        if (n % p == 0)
            return n == p;
    }
    uint64_t d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }
    for (uint64_t a : {2ull, 7ull, 61ull})
        if (!check(n, a, d, s))
            return false;
    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "97 " << isPrime(97) << " (expected true)\n";
    std::cout << "91 " << isPrime(91) << " (expected false)\n";
    return 0;
}
