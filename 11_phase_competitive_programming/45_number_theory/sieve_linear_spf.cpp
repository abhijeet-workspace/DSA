// Teaching lab: linear sieve SPF + factorization
#include <iostream>
#include <vector>

struct LinearSieve {
    std::vector<int> spf, primes;
    explicit LinearSieve(int n) : spf(n + 1) {
        for (int i = 2; i <= n; ++i) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                long long v = 1LL * i * p;
                if (v > n)
                    break;
                spf[static_cast<int>(v)] = p;
                if (p == spf[i])
                    break;
            }
        }
    }
    std::vector<int> factor(int x) const {
        std::vector<int> f;
        while (x > 1) {
            f.push_back(spf[x]);
            x /= spf[x];
        }
        return f;
    }
};

int main() {
    LinearSieve s(100);
    auto f = s.factor(84);
    std::cout << "factor(84):";
    for (int p : f)
        std::cout << " " << p;
    std::cout << " (expected 2 2 3 7)\n";
    std::cout << "primes_count<=100=" << s.primes.size() << " (expected 25)\n";
    return 0;
}
