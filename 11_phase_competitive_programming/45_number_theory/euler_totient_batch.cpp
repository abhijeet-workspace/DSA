// Teaching lab: Euler totient for all 1..N
#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> totientBatch(int n) {
    std::vector<int> phi(n + 1);
    for (int i = 0; i <= n; ++i)
        phi[i] = i;
    for (int p = 2; p <= n; ++p) {
        if (phi[p] == p) { // p prime
            for (int m = p; m <= n; m += p)
                phi[m] -= phi[m] / p;
        }
    }
    return phi;
}

int main() {
    auto phi = totientBatch(10);
    std::cout << "phi(1..10):";
    for (int i = 1; i <= 10; ++i)
        std::cout << " " << phi[i];
    std::cout << "\n";
    std::cout << "phi(12) via batch N=12: ";
    auto phi12 = totientBatch(12);
    std::cout << phi12[12] << " (expected 4)\n";
    long long sum = std::accumulate(phi.begin() + 1, phi.end(), 0LL);
    std::cout << "sum phi(1..10)=" << sum << " (expected 32)\n";
    return 0;
}
