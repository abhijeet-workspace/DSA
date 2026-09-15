// N-th Tribonacci Number — LC 1137
// Recursion + memo (n <= 37).
#include <iostream>
#include <vector>
#include <functional>

int tribonacci(int n) {
    std::vector<int> memo(static_cast<size_t>(n) + 1, -1);
    std::function<int(int)> dfs = [&](int k) -> int {
        if (k == 0) return 0;
        if (k <= 2) return 1;
        int& res = memo[static_cast<size_t>(k)];
        if (res != -1) return res;
        return res = dfs(k - 1) + dfs(k - 2) + dfs(k - 3);
    };
    return dfs(n);
}

int main() {
    std::cout << tribonacci(4) << " (expected 4)\n";
    std::cout << tribonacci(25) << " (expected 1389537)\n";
    return 0;
}
