// The Skyline Problem — https://leetcode.com/problems/the-skyline-problem/
// Sweep line + multiset of active heights; emit when max changes.
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

std::vector<std::vector<int>> getSkyline(const std::vector<std::vector<int>>& buildings) {
    std::vector<std::pair<int, int>> ev;
    for (auto& b : buildings) {
        ev.push_back({b[0], -b[2]});  // start: negative height
        ev.push_back({b[1], b[2]});   // end
    }
    std::sort(ev.begin(), ev.end());
    std::multiset<int> hs{0};
    std::vector<std::vector<int>> ans;
    int prev = 0;
    for (auto [x, h] : ev) {
        if (h < 0) hs.insert(-h);
        else hs.erase(hs.find(h));
        int cur = *hs.rbegin();
        if (cur != prev) {
            ans.push_back({x, cur});
            prev = cur;
        }
    }
    return ans;
}

int main() {
    auto ans = getSkyline({{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}});
    for (auto& p : ans) std::cout << "[" << p[0] << "," << p[1] << "] ";
    std::cout << "\n";
    return 0;
}
