// Unique BSTs — LC 96 Catalan
#include <iostream>
long long catalan(int n) {
    long long c = 1;
    for (int i = 1; i <= n; ++i)
        c = c * (2 * n - i + 1) / i; // C(2n,n) stepwise wrong
    // correct: C(2n,n)/(n+1)
    c = 1;
    for (int i = 1; i <= n; ++i)
        c = c * (n + i) / i; // C(2n,n) = Π (n+i)/i for i=1..n
    return c / (n + 1);
}
int numTrees(int n) {
    return (int)catalan(n);
}
int main() {
    std::cout << numTrees(3) << " (expected 5)\n";
    std::cout << numTrees(1) << " (expected 1)\n";
    return 0;
}
