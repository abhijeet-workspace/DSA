#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
int main() {
    std::vector<std::tuple<int, int, int>> b = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}};
    std::vector<int> xs;
    for (auto [L, R, H] : b) {
        xs.push_back(L);
        xs.push_back(R);
    }
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    auto id = [&](int x) { return int(std::lower_bound(xs.begin(), xs.end(), x) - xs.begin()); };
    int m = (int)xs.size();
    std::vector<int> cover(m, 0);
    for (auto [L, R, H] : b) {
        int l = id(L), r = id(R);
        for (int i = l; i < r; ++i)
            cover[i] = std::max(cover[i], H);
    }
    std::vector<std::pair<int, int>> sky;
    int prev = 0;
    for (int i = 0; i < m - 1; ++i)
        if (cover[i] != prev) {
            sky.push_back({xs[i], cover[i]});
            prev = cover[i];
        }
    if (prev != 0)
        sky.push_back({xs[m - 1], 0});
    const std::vector<std::pair<int, int>> exp = {{2, 10}, {3, 15}, {7, 12}, {12, 0}};
    bool ok = sky == exp;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
