// Prime Checking & Factorization — C++ fundamentals
// O(sqrt(n)) primality and trial factorization.
#include <iostream>
#include <vector>

bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

std::vector<long long> primeFactors(long long n) {
    std::vector<long long> factors;
    if (n <= 1) {
        return factors;
    }
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (long long p = 3; p * p <= n; p += 2) {
        while (n % p == 0) {
            factors.push_back(p);
            n /= p;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int countDistinctPrimeFactors(long long n) {
    auto f = primeFactors(n);
    if (f.empty()) {
        return 0;
    }
    int distinct = 1;
    for (size_t i = 1; i < f.size(); ++i) {
        if (f[i] != f[i - 1]) {
            ++distinct;
        }
    }
    return distinct;
}

int main() {
    std::cout << "isPrime(17) = " << (isPrime(17) ? "true" : "false")
              << " (expected true)\n";
    std::cout << "isPrime(15) = " << (isPrime(15) ? "true" : "false")
              << " (expected false)\n";

    auto f = primeFactors(60);
    std::cout << "factors of 60:";
    for (long long x : f) {
        std::cout << " " << x;
    }
    std::cout << " (expected 2 2 3 5)\n";

    std::cout << "distinct prime factors of 60 = "
              << countDistinctPrimeFactors(60) << " (expected 3)\n";
    return 0;
}
