// Beautiful Arrangement — https://leetcode.com/problems/beautiful-arrangement/
#include <functional>
#include <iostream>
#include <vector>

int countArrangement(int n) {
    std::vector<int> memo(1 << n, -1);
    std::function<int(int, int)> dfs = [&](int pos, int mask) -> int {
        if (pos == n + 1)
            return 1;
        if (memo[static_cast<size_t>(mask)] != -1)
            return memo[static_cast<size_t>(mask)];
        int ans = 0;
        for (int num = 1; num <= n; ++num) {
            if (mask & (1 << (num - 1)))
                continue;
            if (num % pos == 0 || pos % num == 0)
                ans += dfs(pos + 1, mask | (1 << (num - 1)));
        }
        return memo[static_cast<size_t>(mask)] = ans;
    };
    return dfs(1, 0);
}

int main() {
    std::cout << countArrangement(2) << " (expected 2)\n";
    std::cout << countArrangement(1) << " (expected 1)\n";
    return 0;
}
