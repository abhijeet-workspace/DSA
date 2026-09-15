// LC 218 The Skyline Problem
// https://leetcode.com/problems/the-skyline-problem/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>> buildings) {
    std::vector<std::pair<int, int>> ev;
    for (auto& b : buildings) {
        ev.push_back({b[0], -b[2]});
        ev.push_back({b[1], b[2]});
    }
    std::sort(ev.begin(), ev.end());
    std::multiset<int> hs{0};
    std::vector<std::vector<int>> res;
    int prev = 0;
    for (auto [x, h] : ev) {
        if (h < 0)
            hs.insert(-h);
        else
            hs.erase(hs.find(h));
        int cur = *hs.rbegin();
        if (cur != prev) {
            res.push_back({x, cur});
            prev = cur;
        }
    }
    return res;
}
int main() {
    auto r = getSkyline({{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}});
    const std::vector<std::vector<int>> exp = {{2, 10},  {3, 15}, {7, 12}, {12, 0},
                                               {15, 10}, {20, 8}, {24, 0}};
    bool ok = r == exp;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
