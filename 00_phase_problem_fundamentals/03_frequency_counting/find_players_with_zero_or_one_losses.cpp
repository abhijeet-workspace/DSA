// Find Players With Zero or One Losses — LC 2225
#include <iostream>
#include <map>
#include <vector>

std::vector<std::vector<int>> findWinners(const std::vector<std::vector<int>>& matches) {
    std::map<int, int> losses; // player -> loss count (also registers winners with 0)
    for (const auto& m : matches) {
        const int w = m[0], l = m[1];
        if (!losses.count(w))
            losses[w] = 0;
        ++losses[l];
    }
    std::vector<int> zero, one;
    for (const auto& [p, c] : losses) {
        if (c == 0)
            zero.push_back(p);
        else if (c == 1)
            one.push_back(p);
    }
    return {zero, one};
}

int main() {
    auto ans = findWinners(
        {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}});
    std::cout << "zero: ";
    for (int x : ans[0])
        std::cout << x << " ";
    std::cout << "(expected 1 2 10)\none: ";
    for (int x : ans[1])
        std::cout << x << " ";
    std::cout << "(expected 4 5 7 8)\n";
    return 0;
}
