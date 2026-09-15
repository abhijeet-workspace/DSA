// Classic airplane max concurrency (LintCode-style)
#include <algorithm>
#include <iostream>
#include <vector>
int countOfAirplanes(std::vector<std::pair<int, int>> flights) {
    std::vector<std::pair<int, int>> ev;
    for (auto [L, R] : flights) {
        ev.push_back({L, +1});
        ev.push_back({R, -1});
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
    int a = countOfAirplanes({{1, 10}, {2, 3}, {5, 8}, {4, 7}});
    std::cout << "max=" << a << "\n" << (a == 3 ? "OK\n" : "FAIL\n");
    return a == 3 ? 0 : 1;
}
