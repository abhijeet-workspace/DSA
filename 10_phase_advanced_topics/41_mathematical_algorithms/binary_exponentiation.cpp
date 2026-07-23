// Binary Exponentiation — compute base^exp mod m in O(log exp)
// Square base each bit; multiply into result when bit is set.
#include <iostream>

long long fastPow(long long base, long long exp, long long mod) {
    long long result = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    const long long MOD = 1000000007LL;
    std::cout << fastPow(2, 10, MOD) << " (expected 1024)\n";
    std::cout << fastPow(3, 5, MOD) << " (expected 243)\n";
    return 0;
}
