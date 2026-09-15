#include <iostream>
int numOfWays(int n) {
    constexpr int MOD = 1'000'000'007;
    long long a121 = 6, a123 = 6;
    for (int i = 2; i <= n; ++i) {
        long long n121 = (a121 * 3 + a123 * 2) % MOD, n123 = (a121 * 2 + a123 * 2) % MOD;
        a121 = n121;
        a123 = n123;
    }
    return (int)((a121 + a123) % MOD);
}
int main() {
    std::cout << "w(1)=" << numOfWays(1) << " (expected 12)\nw(2)=" << numOfWays(2)
              << " (expected 54)\n";
    return 0;
}
