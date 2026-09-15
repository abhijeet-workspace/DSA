// RNG template — splitmix64-based deterministic RNG for hashing/tests
#include <chrono>
#include <cstdint>
#include <iostream>

struct RNG {
    uint64_t x;
    explicit RNG(uint64_t seed = 0) : x(seed) {
        if (x == 0) {
            x = static_cast<uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());
        }
    }
    uint64_t next() {
        x += 0x9e3779b97f4a7c15ULL;
        uint64_t z = x;
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
        return z ^ (z >> 31);
    }
    int uniform(int l, int r) { // inclusive
        return l + static_cast<int>(next() % static_cast<uint64_t>(r - l + 1));
    }
};

int main() {
    RNG rng(42);
    const int a = rng.uniform(1, 1);
    const int b = rng.uniform(5, 5);
    // deterministic sequence smoke: next values with fixed seed
    RNG r2(1);
    const uint64_t x1 = r2.next();
    const uint64_t x2 = r2.next();
    std::cout << "a=" << a << " b=" << b << " x1=" << x1 << " x2=" << x2 << "\n";
    const bool ok = (a == 1 && b == 5 && x1 != x2);
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
