// Digit Problems — C++ fundamentals
// Count/sum digits, reverse, palindrome, Armstrong.
#include <climits>
#include <iostream>

int countDigits(long long n) {
    if (n < 0) {
        n = -n;
    }
    if (n == 0) {
        return 1;
    }
    int c = 0;
    while (n > 0) {
        n /= 10;
        ++c;
    }
    return c;
}

int sumDigits(long long n) {
    if (n < 0) {
        n = -n;
    }
    int s = 0;
    while (n > 0) {
        s += static_cast<int>(n % 10);
        n /= 10;
    }
    return s;
}

// Returns 0 on overflow (LeetCode-style policy for 32-bit range demo).
int reverseInt(int x) {
    long long rev = 0;
    while (x != 0) {
        int dig = x % 10;
        x /= 10;
        rev = rev * 10 + dig;
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
    }
    return static_cast<int>(rev);
}

bool isPalindromeNumber(int x) {
    if (x < 0) {
        return false;
    }
    return x == reverseInt(x);
}

long long ipow(long long base, int exp) {
    long long r = 1;
    for (int i = 0; i < exp; ++i) {
        r *= base;
    }
    return r;
}

bool isArmstrong(long long n) {
    if (n < 0) {
        return false;
    }
    int k = countDigits(n);
    long long m = n;
    long long sum = 0;
    while (m > 0) {
        int dig = static_cast<int>(m % 10);
        sum += ipow(dig, k);
        m /= 10;
    }
    return sum == n;
}

int main() {
    std::cout << "digits in 371 = " << countDigits(371) << " (expected 3)\n";
    std::cout << "sum digits 371 = " << sumDigits(371) << " (expected 11)\n";
    std::cout << "reverse(123) = " << reverseInt(123) << " (expected 321)\n";
    std::cout << "palindrome(121)? " << (isPalindromeNumber(121) ? "yes" : "no")
              << " (expected yes)\n";
    std::cout << "armstrong(371)? " << (isArmstrong(371) ? "yes" : "no") << " (expected yes)\n";
    std::cout << "armstrong(123)? " << (isArmstrong(123) ? "yes" : "no") << " (expected no)\n";
    return 0;
}
