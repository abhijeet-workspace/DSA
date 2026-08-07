// Series & Sequences — C++ fundamentals
// Fibonacci, AP/GP, factorial, sum of squares.
#include <iostream>

long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long sumAP(long long a, long long d, int n) {
    if (n <= 0) {
        return 0;
    }
    return n * (2 * a + (n - 1) * d) / 2;
}

long long powerBinary(long long base, int exp) {
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

long long sumGP(long long a, long long r, int n) {
    if (n <= 0) {
        return 0;
    }
    if (r == 1) {
        return a * n;
    }
    return a * (powerBinary(r, n) - 1) / (r - 1);
}

unsigned long long factorial(int n) {
    unsigned long long f = 1;
    for (int i = 2; i <= n; ++i) {
        f *= static_cast<unsigned long long>(i);
    }
    return f;
}

long long sumSquaresFormula(int n) {
    return static_cast<long long>(n) * (n + 1) * (2 * n + 1) / 6;
}

long long sumSquaresLoop(int n) {
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        s += static_cast<long long>(i) * i;
    }
    return s;
}

int main() {
    std::cout << "fib(10) = " << fibonacci(10) << " (expected 55)\n";
    std::cout << "sumAP(2,3,4) = " << sumAP(2, 3, 4) << " (expected 26)\n";
    std::cout << "sumGP(2,3,4) = " << sumGP(2, 3, 4) << " (expected 80)\n";
    std::cout << "5! = " << factorial(5) << " (expected 120)\n";
    std::cout << "sum sq formula 5 = " << sumSquaresFormula(5)
              << " (expected 55)\n";
    std::cout << "sum sq loop 5 = " << sumSquaresLoop(5) << " (expected 55)\n";
    return 0;
}
