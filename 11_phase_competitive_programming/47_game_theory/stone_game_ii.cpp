#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int stoneGameII(std::vector<int> piles) {
    int n = piles.size();
    std::vector<int> suf(n + 1);
    for (int i = n - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + piles[i];
    std::vector<std::vector<int>> memo(n, std::vector<int>(n + 1, -1));
    std::function<int(int, int)> dfs = [&](int i, int M) -> int {
        if (i >= n)
            return 0;
        if (2 * M >= n - i)
            return suf[i];
        if (memo[i][M] != -1)
            return memo[i][M];
        int best = 0;
        for (int x = 1; x <= 2 * M; ++x)
            best = std::max(best, suf[i] - dfs(i + x, std::max(M, x)));
        return memo[i][M] = best;
    };
    return dfs(0, 1);
}

int main() {
    std::cout << "stoneGameII=" << stoneGameII({2, 7, 9, 4, 4}) << " (expected 10)\n";
    return 0;
}
