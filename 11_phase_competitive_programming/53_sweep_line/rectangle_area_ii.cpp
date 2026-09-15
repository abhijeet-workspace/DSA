// LC 850 Rectangle Area II
// https://leetcode.com/problems/rectangle-area-ii/
#include <algorithm>
#include <iostream>
#include <vector>
int rectangleArea(std::vector<std::vector<int>> rectangles) {
    const int MOD = 1'000'000'007;
    struct Ev {
        int x, y1, y2, typ;
    };
    std::vector<Ev> ev;
    std::vector<int> ys;
    for (auto& r : rectangles) {
        ev.push_back({r[0], r[1], r[3], +1});
        ev.push_back({r[2], r[1], r[3], -1});
        ys.push_back(r[1]);
        ys.push_back(r[3]);
    }
    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    auto id = [&](int y) { return int(std::lower_bound(ys.begin(), ys.end(), y) - ys.begin()); };
    int m = (int)ys.size();
    std::vector<int> cover(std::max(0, m - 1), 0);
    auto ylen = [&]() {
        long long len = 0;
        for (int i = 0; i + 1 < m; ++i)
            if (cover[i] > 0)
                len += ys[i + 1] - ys[i];
        return len;
    };
    std::sort(ev.begin(), ev.end(), [](const Ev& a, const Ev& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return a.typ > b.typ;
    });
    long long area = 0;
    for (size_t i = 0; i + 1 < ev.size(); ++i) {
        int l = id(ev[i].y1), r = id(ev[i].y2);
        for (int k = l; k < r; ++k)
            cover[k] += ev[i].typ;
        area = (area + ylen() * (ev[i + 1].x - ev[i].x)) % MOD;
    }
    return (int)area;
}
int main() {
    int a = rectangleArea({{0, 0, 2, 2}, {1, 0, 2, 3}, {1, 0, 3, 1}});
    std::cout << "area=" << a << "\n" << (a == 6 ? "OK\n" : "FAIL\n");
    return a == 6 ? 0 : 1;
}
