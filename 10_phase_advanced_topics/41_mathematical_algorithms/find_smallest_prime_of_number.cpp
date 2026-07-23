// Smallest n-digit prime — scan upward from 10^(n-1) with trial primality
#include <iostream>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; static_cast<long long>(i) * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int smallestNDigitPrime(int n) {
    if (n <= 0) {
        return -1;
    }
    int upper = 1;
    for (int i = 0; i < n; ++i) {
        upper *= 10;
    }
    --upper; // 10^n - 1
    int lower = (n == 1) ? 2 : (upper + 1) / 10; // 10^(n-1); skip 1 for n=1
    for (int num = lower; num <= upper; ++num) {
        if (isPrime(num)) {
            return num;
        }
    }
    return -1;
}

int main() {
    std::cout << smallestNDigitPrime(1) << " (expected 2)\n";
    std::cout << smallestNDigitPrime(2) << " (expected 11)\n";
    std::cout << smallestNDigitPrime(3) << " (expected 101)\n";
    return 0;
}
