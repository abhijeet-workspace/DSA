#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <set>
#include <vector>
double closestPair(std::vector<std::pair<double, double>> pts) {
    std::sort(pts.begin(), pts.end());
    double best = std::numeric_limits<double>::infinity();
    std::set<std::pair<double, double>> active; // y,x
    int left = 0;
    for (size_t i = 0; i < pts.size(); ++i) {
        auto [x, y] = pts[i];
        while (left < (int)i && x - pts[left].first > best) {
            active.erase({pts[left].second, pts[left].first});
            ++left;
        }
        auto lo = active.lower_bound({y - best, -1e100});
        auto hi = active.upper_bound({y + best, 1e100});
        for (auto it = lo; it != hi; ++it) {
            double dx = x - it->second, dy = y - it->first;
            best = std::min(best, std::hypot(dx, dy));
        }
        active.insert({y, x});
    }
    return best;
}
int main() {
    std::vector<std::pair<double, double>> pts = {{0, 0}, {1, 1}, {2, 2}, {0.5, 0.4}};
    double d = closestPair(pts), brute = 1e100;
    for (size_t i = 0; i < pts.size(); ++i)
        for (size_t j = i + 1; j < pts.size(); ++j)
            brute = std::min(
                brute, std::hypot(pts[i].first - pts[j].first, pts[i].second - pts[j].second));
    bool ok = std::abs(d - brute) < 1e-9;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
