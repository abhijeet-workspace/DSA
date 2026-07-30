// Subtract the Product and Sum of Digits — LC 1281
// Pop digits: maintain product and sum; return product - sum.
#include <iostream>

int subtractProductAndSum(int n) {
    int prod = 1, sum = 0;
    while (n) {
        const int d = n % 10;
        prod *= d;
        sum += d;
        n /= 10;
    }
    return prod - sum;
}

int main() {
    std::cout << subtractProductAndSum(234) << " (expected 15)\n"
              << subtractProductAndSum(4421) << " (expected 21)\n";
    return 0;
}
