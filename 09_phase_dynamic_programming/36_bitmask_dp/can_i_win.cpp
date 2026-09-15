// Can I Win — https://leetcode.com/problems/can-i-win/
#include <functional>
#include <iostream>
#include <vector>

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    const int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
    if (sum < desiredTotal) return false;
    if (desiredTotal <= 0) return true;
    std::vector<int> memo(1 << maxChoosableInteger, -1);
    std::function<bool(int, int)> dfs = [&](int mask, int remain) -> bool {
        if (memo[static_cast<size_t>(mask)] != -1) return memo[static_cast<size_t>(mask)];
        for (int i = 0; i < maxChoosableInteger; ++i) {
            if (mask & (1 << i)) continue;
            if (i + 1 >= remain || !dfs(mask | (1 << i), remain - (i + 1)))
                return memo[static_cast<size_t>(mask)] = 1;
        }
        return memo[static_cast<size_t>(mask)] = 0;
    };
    return dfs(0, desiredTotal);
}

int main() {
    std::cout << std::boolalpha << canIWin(10, 11) << " (expected false)\n";
    std::cout << canIWin(10, 0) << " (expected true)\n";
    std::cout << canIWin(10, 1) << " (expected true)\n";
    return 0;
}
