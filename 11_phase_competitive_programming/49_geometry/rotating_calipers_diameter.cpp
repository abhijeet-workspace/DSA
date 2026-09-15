// Teaching lab: diameter via hull + rotating calipers
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

struct Pt {
    long long x, y;
    bool operator<(const Pt& o) const { return x < o.x || (x == o.x && y < o.y); }
};

long long cross(Pt a, Pt b, Pt c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

long long dist2(Pt a, Pt b) {
    long long dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

std::vector<Pt> hull(std::vector<Pt> p) {
    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(), p.end(), [](Pt a, Pt b) { return a.x == b.x && a.y == b.y; }),
            p.end());
    if (p.size() <= 1)
        return p;
    std::vector<Pt> lo, hi;
    for (auto pt : p) {
        while (lo.size() >= 2 && cross(lo[lo.size() - 2], lo.back(), pt) <= 0)
            lo.pop_back();
        lo.push_back(pt);
    }
    for (int i = (int)p.size() - 1; i >= 0; --i) {
        auto pt = p[i];
        while (hi.size() >= 2 && cross(hi[hi.size() - 2], hi.back(), pt) <= 0)
            hi.pop_back();
        hi.push_back(pt);
    }
    lo.pop_back();
    hi.pop_back();
    lo.insert(lo.end(), hi.begin(), hi.end());
    return lo;
}

double diameter(std::vector<Pt> pts) {
    auto h = hull(std::move(pts));
    int m = static_cast<int>(h.size());
    if (m == 1)
        return 0;
    if (m == 2)
        return std::sqrt((double)dist2(h[0], h[1]));
    long long best = 0;
    int j = 1;
    for (int i = 0; i < m; ++i) {
        int ni = (i + 1) % m;
        while (true) {
            int nj = (j + 1) % m;
            long long cross1 = std::abs(cross(h[i], h[ni], h[nj]));
            long long cross0 = std::abs(cross(h[i], h[ni], h[j]));
            if (cross1 > cross0)
                j = nj;
            else
                break;
        }
        best = std::max(best, dist2(h[i], h[j]));
        best = std::max(best, dist2(h[ni], h[j]));
    }
    return std::sqrt((double)best);
}

int main() {
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "diameter=" << diameter({{0, 0}, {1, 0}, {1, 1}, {0, 1}})
              << " (expected 1.41421)\n";
    return 0;
}
