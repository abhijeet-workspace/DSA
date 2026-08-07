// Sieve & Totient Intro — C++ fundamentals
// Eratosthenes, phi(n), totient sieve for 1..N.
#include <iostream>
#include <vector>

std::vector<int> sievePrimes(int n) {
    std::vector<int> primes;
    if (n < 2) {
        return primes;
    }
    std::vector<char> isPrime(static_cast<size_t>(n) + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int p = 2; static_cast<long long>(p) * p <= n; ++p) {
        if (isPrime[static_cast<size_t>(p)]) {
            for (long long j = static_cast<long long>(p) * p; j <= n; j += p) {
                isPrime[static_cast<size_t>(j)] = 0;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (isPrime[static_cast<size_t>(i)]) {
            primes.push_back(i);
        }
    }
    return primes;
}

long long phi(long long n) {
    long long result = n;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

std::vector<long long> totientSieve(int n) {
    std::vector<long long> ph(static_cast<size_t>(n) + 1);
    for (int i = 0; i <= n; ++i) {
        ph[static_cast<size_t>(i)] = i;
    }
    for (int p = 2; p <= n; ++p) {
        if (ph[static_cast<size_t>(p)] == p) { // p is prime
            for (int j = p; j <= n; j += p) {
                ph[static_cast<size_t>(j)] -= ph[static_cast<size_t>(j)] / p;
            }
        }
    }
    return ph;
}

int main() {
    auto primes = sievePrimes(10);
    std::cout << "primes <= 10:";
    for (int p : primes) {
        std::cout << " " << p;
    }
    std::cout << " (expected 2 3 5 7)\n";

    std::cout << "phi(9) = " << phi(9) << " (expected 6)\n";
    std::cout << "phi(1) = " << phi(1) << " (expected 1)\n";

    auto ph = totientSieve(6);
    std::cout << "phi 1..6:";
    for (int i = 1; i <= 6; ++i) {
        std::cout << " " << ph[static_cast<size_t>(i)];
    }
    std::cout << " (expected 1 1 2 2 4 2)\n";
    return 0;
}
