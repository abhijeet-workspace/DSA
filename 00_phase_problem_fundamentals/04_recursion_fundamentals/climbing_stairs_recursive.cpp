// Climbing Stairs — LC 70 (recursive + memo)
#include <functional>
#include <iostream>
#include <vector>

int climbStairs(int n) {
    std::vector<int> memo(static_cast<size_t>(n) + 1, -1);
    std::function<int(int)> dfs = [&](int k) -> int {
        if (k <= 2)
            return k;
        int& res = memo[static_cast<size_t>(k)];
        if (res != -1)
            return res;
        return res = dfs(k - 1) + dfs(k - 2);
    };
    return dfs(n);
}

int main() {
    std::cout << climbStairs(2) << " (expected 2)\n";
    std::cout << climbStairs(3) << " (expected 3)\n";
    return 0;
}
