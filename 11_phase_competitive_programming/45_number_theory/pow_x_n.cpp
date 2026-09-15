// LC50 Pow(x, n) — binary exponentiation
#include <iomanip>
#include <iostream>

double myPow(double x, int n) {
    long long exp = n;
    if (exp < 0) {
        x = 1.0 / x;
        exp = -exp;
    }
    double ans = 1.0;
    while (exp > 0) {
        if (exp & 1)
            ans *= x;
        x *= x;
        exp >>= 1;
    }
    return ans;
}

int main() {
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "myPow(2,10)=" << myPow(2, 10) << " (expected 1024.00000)\n";
    std::cout << "myPow(2,-2)=" << myPow(2, -2) << " (expected 0.25000)\n";
    return 0;
}
