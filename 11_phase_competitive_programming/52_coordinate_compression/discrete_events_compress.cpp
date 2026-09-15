#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::vector<std::pair<int, int>> intervals = {{100, 250}, {200, 300}, {1000, 1001}};
    std::vector<int> coords;
    for (auto [L, R] : intervals) {
        coords.push_back(L);
        coords.push_back(R);
    }
    std::sort(coords.begin(), coords.end());
    coords.erase(std::unique(coords.begin(), coords.end()), coords.end());
    auto id = [&](int x) {
        return int(std::lower_bound(coords.begin(), coords.end(), x) - coords.begin());
    };
    std::vector<int> diff(coords.size(), 0);
    for (auto [L, R] : intervals) {
        ++diff[id(L)];
        --diff[id(R)];
    }
    int cur = 0, mx = 0;
    for (int d : diff) {
        cur += d;
        mx = std::max(mx, cur);
    }
    std::cout << "max_overlap=" << mx << " expected=2\n" << (mx == 2 ? "OK\n" : "FAIL\n");
    return mx == 2 ? 0 : 1;
}
