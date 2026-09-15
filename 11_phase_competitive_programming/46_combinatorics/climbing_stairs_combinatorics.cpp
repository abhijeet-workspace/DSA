// Climbing Stairs — combinatorics view LC 70
#include <iostream>
static long long C(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    long long ans = 1;
    for (int i = 1; i <= k; ++i)
        ans = ans * (n - k + i) / i;
    return ans;
}
int climbStairs(int n) {
    long long ans = 0;
    for (int k = 0; k <= n / 2; ++k)
        ans += C(n - k, k);
    return (int)ans;
}
int main() {
    std::cout << climbStairs(3) << " (expected 3)\n";
    std::cout << climbStairs(5) << " (expected 8)\n";
    return 0;
}
