#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::vector<std::pair<int, int>> pts = {{1000, -5}, {7, 1000}, {1000, 3}, {7, -5}};
    std::vector<int> xs, ys;
    for (auto [x, y] : pts) {
        xs.push_back(x);
        ys.push_back(y);
    }
    auto uniq = [](std::vector<int>& v) {
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
    };
    uniq(xs);
    uniq(ys);
    auto rx = [&](int x) {
        return int(std::lower_bound(xs.begin(), xs.end(), x) - xs.begin()) + 1;
    };
    auto ry = [&](int y) {
        return int(std::lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1;
    };
    std::vector<std::pair<int, int>> c;
    for (auto [x, y] : pts)
        c.push_back({rx(x), ry(y)});
    const std::vector<std::pair<int, int>> exp = {{2, 1}, {1, 3}, {2, 2}, {1, 1}};
    bool ok = c == exp;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
