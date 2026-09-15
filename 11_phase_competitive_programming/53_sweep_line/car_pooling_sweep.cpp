// LC 1094 Car Pooling
// https://leetcode.com/problems/car-pooling/
#include <algorithm>
#include <iostream>
#include <vector>
bool carPooling(std::vector<std::vector<int>> trips, int capacity) {
    std::vector<std::pair<int, int>> ev;
    for (auto& t : trips) {
        ev.push_back({t[1], +t[0]});
        ev.push_back({t[2], -t[0]});
    }
    std::sort(ev.begin(), ev.end());
    int cur = 0;
    for (auto [x, d] : ev) {
        cur += d;
        if (cur > capacity)
            return false;
    }
    return true;
}
int main() {
    bool a = carPooling({{2, 1, 5}, {3, 3, 7}}, 4);
    bool b = carPooling({{2, 1, 5}, {3, 3, 7}}, 5);
    bool ok = !a && b;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
