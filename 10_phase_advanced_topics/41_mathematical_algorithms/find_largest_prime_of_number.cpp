// Largest n-digit prime — scan downward from 10^n-1 with trial primality
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

int largestNDigitPrime(int n) {
    if (n <= 0) {
        return -1;
    }
    int upper = 1;
    for (int i = 0; i < n; ++i) {
        upper *= 10;
    }
    --upper; // 10^n - 1
    int lower = (n == 1) ? 1 : (upper + 1) / 10; // 10^(n-1)
    for (int num = upper; num >= lower; --num) {
        if (isPrime(num)) {
            return num;
        }
    }
    return -1;
}

int main() {
    std::cout << largestNDigitPrime(1) << " (expected 7)\n";
    std::cout << largestNDigitPrime(2) << " (expected 97)\n";
    std::cout << largestNDigitPrime(3) << " (expected 997)\n";
    return 0;
}
