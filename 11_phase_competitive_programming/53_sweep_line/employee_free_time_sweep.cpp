// LC 759 Employee Free Time
// https://leetcode.com/problems/employee-free-time/
#include <algorithm>
#include <iostream>
#include <vector>
std::vector<std::pair<int, int>>
employeeFreeTime(std::vector<std::vector<std::pair<int, int>>> schedule) {
    std::vector<std::pair<int, int>> all;
    for (auto& emp : schedule)
        for (auto& iv : emp)
            all.push_back(iv);
    std::sort(all.begin(), all.end());
    std::vector<std::pair<int, int>> merged;
    for (auto iv : all) {
        if (merged.empty() || merged.back().second < iv.first)
            merged.push_back(iv);
        else
            merged.back().second = std::max(merged.back().second, iv.second);
    }
    std::vector<std::pair<int, int>> gaps;
    for (size_t i = 1; i < merged.size(); ++i)
        gaps.push_back({merged[i - 1].second, merged[i].first});
    return gaps;
}
int main() {
    auto g = employeeFreeTime({{{1, 2}, {5, 6}}, {{1, 3}}, {{4, 10}}});
    const std::vector<std::pair<int, int>> exp = {{3, 4}};
    bool ok = g == exp;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
