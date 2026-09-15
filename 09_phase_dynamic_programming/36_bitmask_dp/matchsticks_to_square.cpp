// Matchsticks to Square — https://leetcode.com/problems/matchsticks-to-square/
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

bool makesquare(std::vector<int>& matchsticks) {
    const int total = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (total % 4) return false;
    const int side = total / 4;
    std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
    if (matchsticks[0] > side) return false;
    std::vector<int> sides(4, 0);
    std::function<bool(int)> dfs = [&](int i) -> bool {
        if (i == static_cast<int>(matchsticks.size())) return true;
        for (int s = 0; s < 4; ++s) {
            if (sides[static_cast<size_t>(s)] + matchsticks[static_cast<size_t>(i)] > side) continue;
            sides[static_cast<size_t>(s)] += matchsticks[static_cast<size_t>(i)];
            if (dfs(i + 1)) return true;
            sides[static_cast<size_t>(s)] -= matchsticks[static_cast<size_t>(i)];
            if (sides[static_cast<size_t>(s)] == 0) break;
        }
        return false;
    };
    return dfs(0);
}

int main() {
    std::vector<int> a{1, 1, 2, 2, 2}, b{3, 3, 3, 3, 4};
    std::cout << std::boolalpha << makesquare(a) << " (expected true)\n";
    std::cout << makesquare(b) << " (expected false)\n";
    return 0;
}
