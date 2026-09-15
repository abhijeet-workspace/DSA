#include <functional>
#include <iostream>
#include <vector>

bool canIWin(int m, int desired) {
    int sum = m * (m + 1) / 2;
    if (sum < desired)
        return false;
    if (desired <= 0)
        return true;
    std::vector<int> memo(1 << m, -1);
    std::function<bool(int, int)> dfs = [&](int mask, int rem) -> bool {
        if (memo[mask] != -1)
            return memo[mask];
        for (int i = 0; i < m; ++i)
            if (!(mask & (1 << i))) {
                int x = i + 1;
                if (x >= rem || !dfs(mask | (1 << i), rem - x))
                    return (memo[mask] = 1);
            }
        return (memo[mask] = 0);
    };
    return dfs(0, desired);
}

int main() {
    std::cout << std::boolalpha << "canIWin(10,11)=" << canIWin(10, 11) << " (expected false)\n"
              << "canIWin(10,1)=" << canIWin(10, 1) << " (expected true)\n";
    return 0;
}
