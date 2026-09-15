// LC 253 Meeting Rooms II
// https://leetcode.com/problems/meeting-rooms-ii/
#include <algorithm>
#include <iostream>
#include <vector>
int minMeetingRooms(std::vector<std::vector<int>> intervals) {
    std::vector<std::pair<int, int>> ev;
    for (auto& it : intervals) {
        ev.push_back({it[0], +1});
        ev.push_back({it[1], -1});
    }
    std::sort(ev.begin(), ev.end(), [](auto& a, auto& b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    });
    int cur = 0, mx = 0;
    for (auto [x, d] : ev) {
        cur += d;
        mx = std::max(mx, cur);
    }
    return mx;
}
int main() {
    int a = minMeetingRooms({{0, 30}, {5, 10}, {15, 20}});
    int b = minMeetingRooms({{7, 10}, {2, 4}});
    bool ok = a == 2 && b == 1;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
