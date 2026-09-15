// Teaching lab: closest pair (divide and conquer)
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

struct Pt {
    double x, y;
};

double dist(Pt a, Pt b) {
    return std::hypot(a.x - b.x, a.y - b.y);
}

double brute(std::vector<Pt>& p, int l, int r) {
    double d = std::numeric_limits<double>::infinity();
    for (int i = l; i < r; ++i)
        for (int j = i + 1; j < r; ++j)
            d = std::min(d, dist(p[i], p[j]));
    return d;
}

double stripClosest(std::vector<Pt>& strip, double d) {
    std::sort(strip.begin(), strip.end(), [](Pt a, Pt b) { return a.y < b.y; });
    for (size_t i = 0; i < strip.size(); ++i)
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; ++j)
            d = std::min(d, dist(strip[i], strip[j]));
    return d;
}

double rec(std::vector<Pt>& px, int l, int r) {
    if (r - l <= 3)
        return brute(px, l, r);
    int m = (l + r) / 2;
    double midX = px[m].x;
    double d = std::min(rec(px, l, m), rec(px, m, r));
    std::vector<Pt> strip;
    for (int i = l; i < r; ++i)
        if (std::fabs(px[i].x - midX) < d)
            strip.push_back(px[i]);
    return std::min(d, stripClosest(strip, d));
}

double closestPair(std::vector<Pt> pts) {
    std::sort(pts.begin(), pts.end(), [](Pt a, Pt b) { return a.x < b.x; });
    return rec(pts, 0, static_cast<int>(pts.size()));
}

int main() {
    std::vector<Pt> pts = {{0, 0}, {3, 4}, {1, 1}, {10, 10}};
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "closest=" << closestPair(pts) << " (expected 1.41421)\n";
    return 0;
}
