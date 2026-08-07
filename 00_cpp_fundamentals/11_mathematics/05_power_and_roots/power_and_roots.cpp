// Power & Roots — C++ fundamentals
// Naive/binary exponentiation, integer sqrt, perfect power checks.
#include <iostream>

long long powerNaive(long long base, int exp) {
    long long r = 1;
    for (int i = 0; i < exp; ++i) {
        r *= base;
    }
    return r;
}

long long powerBinary(long long base, long long exp) {
    long long ans = 1;
    while (exp > 0) {
        if (exp & 1) {
            ans *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return ans;
}

long long isqrt(long long n) {
    if (n < 0) {
        return -1;
    }
    long long lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (mid == 0 || mid <= n / mid) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

bool isPerfectSquare(long long n) {
    if (n < 0) {
        return false;
    }
    long long r = isqrt(n);
    return r * r == n;
}

bool isPowerOfK(long long n, long long k) {
    if (n <= 0 || k <= 1) {
        return n == 1 && k > 0;
    }
    while (n % k == 0) {
        n /= k;
    }
    return n == 1;
}

int main() {
    std::cout << "2^10 naive = " << powerNaive(2, 10) << " (expected 1024)\n";
    std::cout << "2^10 binary = " << powerBinary(2, 10) << " (expected 1024)\n";
    std::cout << "isqrt(10) = " << isqrt(10) << " (expected 3)\n";
    std::cout << "perfect square 16? " << (isPerfectSquare(16) ? "yes" : "no")
              << " (expected yes)\n";
    std::cout << "81 power of 3? " << (isPowerOfK(81, 3) ? "yes" : "no")
              << " (expected yes)\n";
    return 0;
}
