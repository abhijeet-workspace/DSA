// C(n,k) multiplicative
#include <iostream>
long long combinations(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    k = std::min(k, n - k);
    long long ans = 1;
    for (int i = 1; i <= k; ++i)
        ans = ans * (n - k + i) / i;
    return ans;
}
int main() {
    std::cout << combinations(5, 3) << " (expected 10)\n";
    return 0;
}
