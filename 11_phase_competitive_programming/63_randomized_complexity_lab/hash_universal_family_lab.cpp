// Universal hash family lab — ((ax+b) mod p) mod m
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

int main() {
    const uint64_t p = 1000003ULL;
    const int m = 64, N = 200;
    std::mt19937_64 rng{42};
    uint64_t a = rng() % (p - 1) + 1;
    uint64_t b = rng() % p;
    auto h = [&](uint64_t x) { return ((a * x + b) % p) % m; };
    std::vector<int> bucket(m);
    for (int i = 0; i < N; ++i)
        ++bucket[h(rng() % 10000)];
    int mx = 0;
    for (int c : bucket)
        mx = std::max(mx, c);
    std::cout << "maxLoad=" << mx << " avg=" << double(N) / m << "\n";
    return 0;
}
