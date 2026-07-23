// Sum of 1..n — closed form n*(n+1)/2 (watch overflow for large n)
#include <iostream>

long long sumOfN(long long n) {
    if (n < 0) {
        return -1;
    }
    return n * (n + 1) / 2;
}

int main() {
    std::cout << sumOfN(0) << " (expected 0)\n";
    std::cout << sumOfN(1) << " (expected 1)\n";
    std::cout << sumOfN(10) << " (expected 55)\n";
    std::cout << sumOfN(100) << " (expected 5050)\n";
    return 0;
}
