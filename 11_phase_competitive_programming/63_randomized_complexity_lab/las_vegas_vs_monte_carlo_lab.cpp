// Las Vegas vs Monte Carlo lab
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

// Las Vegas: always correct; runtime random
int lasVegasFind(std::vector<int> a, int key) {
    while (true) {
        int i = std::rand() % a.size();
        if (a[i] == key)
            return i; // assumes key exists
    }
}

uint64_t mod_pow(uint64_t a, uint64_t e, uint64_t m) {
    uint64_t r = 1;
    while (e) {
        if (e & 1)
            r = (__uint128_t)r * a % m;
        a = (__uint128_t)a * a % m;
        e >>= 1;
    }
    return r;
}

// Monte Carlo: may err; time bounded
bool fermatMaybePrime(uint64_t n, uint64_t a) {
    if (n < 2)
        return false;
    return mod_pow(a, n - 1, n) == 1;
}

int main() {
    std::srand(1);
    std::vector<int> a = {1, 7, 3, 9};
    std::cout << "LV index=" << lasVegasFind(a, 7) << " (always correct)\n";
    // 561 = 3*11*17 Carmichael; Fermat base 2 says "prime-like"
    std::cout << "MC fermat(561,2)=" << fermatMaybePrime(561, 2)
              << " (true would be false positive; composite)\n";
    return 0;
}
