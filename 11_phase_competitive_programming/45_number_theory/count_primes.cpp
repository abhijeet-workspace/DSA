// LC204 Count Primes — sieve then count
#include <iostream>
#include <vector>

int countPrimes(int n) {
    if (n <= 2)
        return 0;
    std::vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; 1LL * p * p < n; ++p) {
        if (!is_prime[p])
            continue;
        for (int i = p * p; i < n; i += p)
            is_prime[i] = false;
    }
    int cnt = 0;
    for (int i = 2; i < n; ++i)
        cnt += is_prime[i];
    return cnt;
}

int main() {
    std::cout << "countPrimes(10)=" << countPrimes(10) << " (expected 4)\n";
    std::cout << "countPrimes(0)=" << countPrimes(0) << " (expected 0)\n";
    std::cout << "countPrimes(2)=" << countPrimes(2) << " (expected 0)\n";
    return 0;
}
