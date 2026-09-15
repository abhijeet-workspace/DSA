// Pollard Rho factor lab — small composites
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <numeric>

uint64_t mul(uint64_t a, uint64_t b, uint64_t mod) {
    return (__uint128_t)a * b % mod;
}
uint64_t f(uint64_t x, uint64_t c, uint64_t mod) {
    return (mul(x, x, mod) + c) % mod;
}
uint64_t rho(uint64_t n) {
    if (n % 2 == 0)
        return 2;
    uint64_t x = std::rand() % n, y = x, c = 1 + std::rand() % (n - 1), d = 1;
    while (d == 1) {
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
        uint64_t diff = x > y ? x - y : y - x;
        d = std::gcd(diff, n);
        if (d == n)
            return rho(n); // retry
    }
    return d;
}

int main() {
    std::srand(11);
    uint64_t n = 91;
    uint64_t fac = rho(n);
    std::cout << "factor of " << n << " = " << fac << " (expected 7 or 13)\n";
    return 0;
}
