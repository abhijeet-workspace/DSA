// Climbing Stairs — https://leetcode.com/problems/climbing-stairs/
// n steps; 1 or 2 at a time; count distinct ways (Fibonacci).
#include <iostream>

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    int prev2 = 1; // ways(1)
    int prev1 = 2; // ways(2)
    for (int i = 3; i <= n; ++i) {
        const int cur = prev1 + prev2; // last step 1 or 2
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    std::cout << climbStairs(2) << " (expected 2)\n"
              << climbStairs(5) << " (expected 8)\n";
    return 0;
}
