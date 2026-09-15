// Dungeon Game — https://leetcode.com/problems/dungeon-game/
#include <algorithm>
#include <iostream>
#include <vector>

int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
    const int m = static_cast<int>(dungeon.size());
    const int n = static_cast<int>(dungeon[0].size());
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 1e9));
    dp[m][n - 1] = dp[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            const int need = std::min(dp[i + 1][j], dp[i][j + 1]) -
                             dungeon[static_cast<size_t>(i)][static_cast<size_t>(j)];
            dp[i][j] = need <= 0 ? 1 : need;
        }
    }
    return dp[0][0];
}

int main() {
    std::vector<std::vector<int>> d{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    std::cout << calculateMinimumHP(d) << " (expected 7)\n";
    return 0;
}
