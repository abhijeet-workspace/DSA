// Unique Paths — LC 62 (binomial)
#include <iostream>
long long uniquePaths(int m, int n) {
    if (m > n)
        std::swap(m, n);
    long long ans = 1;
    for (int i = 1; i < m; ++i)
        ans = ans * (n - 1 + i) / i;
    return ans;
}
int main() {
    std::cout << uniquePaths(3, 7) << " (expected 28)\n";
    std::cout << uniquePaths(3, 2) << " (expected 3)\n";
    return 0;
}
