// Euler's Totient φ(n) — count k in [1,n] with gcd(k,n)=1
// Factorize and apply φ(n)=n∏(1-1/p) over distinct primes p.
#include <iostream>

int eulerTotient(int n) {
    int result = n;
    for (int p = 2; static_cast<long long>(p) * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    if (n > 1) {
        result -= result / n; // remaining prime factor
    }
    return result;
}

int main() {
    for (int n : {1, 6, 7, 12, 36}) {
        std::cout << "phi(" << n << ")=" << eulerTotient(n) << "\n";
    }
    std::cout << "(expected phi: 1,2,6,4,12)\n";
    return 0;
}
