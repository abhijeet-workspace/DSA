// Teaching lab: Andrew monotone chain
#include <algorithm>
#include <iostream>
#include <vector>

struct Pt {
    long long x, y;
    bool operator<(const Pt& o) const { return x < o.x || (x == o.x && y < o.y); }
    bool operator==(const Pt& o) const { return x == o.x && y == o.y; }
};

long long cross(Pt o, Pt a, Pt b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

std::vector<Pt> andrewHull(std::vector<Pt> pts) {
    std::sort(pts.begin(), pts.end());
    pts.erase(std::unique(pts.begin(), pts.end()), pts.end());
    if (pts.size() <= 1)
        return pts;
    std::vector<Pt> lo, hi;
    for (auto& p : pts) {
        while (lo.size() >= 2 && cross(lo[lo.size() - 2], lo.back(), p) <= 0)
            lo.pop_back();
        lo.push_back(p);
    }
    for (int i = static_cast<int>(pts.size()) - 1; i >= 0; --i) {
        auto& p = pts[i];
        while (hi.size() >= 2 && cross(hi[hi.size() - 2], hi.back(), p) <= 0)
            hi.pop_back();
        hi.push_back(p);
    }
    lo.pop_back();
    hi.pop_back();
    lo.insert(lo.end(), hi.begin(), hi.end());
    return lo;
}

int main() {
    auto h = andrewHull({{0, 0}, {0, 2}, {2, 0}, {2, 2}, {1, 1}});
    std::cout << "hull_size=" << h.size() << " (expected 4)\n";
    for (auto& p : h)
        std::cout << "(" << p.x << "," << p.y << ") ";
    std::cout << "\n";
    return 0;
}
