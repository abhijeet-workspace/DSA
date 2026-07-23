// Sieve of Eratosthenes (+ segmented sieve for [lo, hi])
// Mark multiples of each prime p starting at p^2.
#include <cmath>
#include <iostream>
#include <vector>

std::vector<bool> sieve(int n) {
    std::vector<bool> isPrime(n + 1, true);
    if (n >= 0) {
        isPrime[0] = false;
    }
    if (n >= 1) {
        isPrime[1] = false;
    }
    for (int p = 2; static_cast<long long>(p) * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    return isPrime;
}

std::vector<int> segmentedSieve(int lo, int hi) {
    int limit = static_cast<int>(std::sqrt(hi)) + 1;
    std::vector<bool> smallPrimes = sieve(limit);
    std::vector<bool> isPrime(hi - lo + 1, true);
    if (lo == 0 && hi >= 0) {
        isPrime[0] = false;
    }
    if (lo <= 1 && hi >= 1) {
        isPrime[1 - lo] = false;
    }
    for (int p = 2; p <= limit; ++p) {
        if (!smallPrimes[p]) {
            continue;
        }
        long long start = std::max(static_cast<long long>(p) * p,
                                   ((lo + p - 1LL) / p) * p);
        for (long long i = start; i <= hi; i += p) {
            isPrime[static_cast<int>(i - lo)] = false;
        }
    }
    std::vector<int> primes;
    for (int i = lo; i <= hi; ++i) {
        if (isPrime[i - lo]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    std::vector<bool> isPrime = sieve(50);
    std::cout << "primes<=50:";
    for (int i = 2; i <= 50; ++i) {
        if (isPrime[i]) {
            std::cout << " " << i;
        }
    }
    std::cout << "\n";

    std::vector<int> large = segmentedSieve(990, 1010);
    std::cout << "primes[990,1010]:";
    for (int p : large) {
        std::cout << " " << p;
    }
    std::cout << " (expected 991 997 1009)\n";
    return 0;
}
