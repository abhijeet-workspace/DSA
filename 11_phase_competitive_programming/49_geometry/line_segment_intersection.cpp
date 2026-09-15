// Teaching lab: segment intersection
#include <algorithm>
#include <iostream>

struct Pt {
    long long x, y;
};

int orient(Pt a, Pt b, Pt c) {
    long long v = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (v == 0)
        return 0;
    return v > 0 ? 1 : 2;
}

bool onSeg(Pt a, Pt b, Pt p) {
    return std::min(a.x, b.x) <= p.x && p.x <= std::max(a.x, b.x) && std::min(a.y, b.y) <= p.y &&
           p.y <= std::max(a.y, b.y);
}

bool segmentsIntersect(Pt a, Pt b, Pt c, Pt d) {
    int o1 = orient(a, b, c), o2 = orient(a, b, d);
    int o3 = orient(c, d, a), o4 = orient(c, d, b);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSeg(a, b, c))
        return true;
    if (o2 == 0 && onSeg(a, b, d))
        return true;
    if (o3 == 0 && onSeg(c, d, a))
        return true;
    if (o4 == 0 && onSeg(c, d, b))
        return true;
    return false;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "cross=" << segmentsIntersect({1, 1}, {10, 1}, {1, 2}, {10, 2})
              << " (expected false)\n";
    std::cout << "cross2=" << segmentsIntersect({1, 1}, {10, 10}, {1, 10}, {10, 1})
              << " (expected true)\n";
    return 0;
}
