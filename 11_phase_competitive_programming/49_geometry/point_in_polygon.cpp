// Teaching lab: point-in-polygon ray casting
#include <iostream>
#include <vector>

struct Pt {
    double x, y;
};

bool pointInPoly(const std::vector<Pt>& poly, Pt q) {
    bool inside = false;
    int n = static_cast<int>(poly.size());
    for (int i = 0, j = n - 1; i < n; j = i++) {
        const Pt &a = poly[i], &b = poly[j];
        bool intersect = ((a.y > q.y) != (b.y > q.y)) &&
                         (q.x < (b.x - a.x) * (q.y - a.y) / (b.y - a.y + 0.0) + a.x);
        if (intersect)
            inside = !inside;
    }
    return inside;
}

int main() {
    std::vector<Pt> sq = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    std::cout << std::boolalpha;
    std::cout << "inside(1,1)=" << pointInPoly(sq, {1, 1}) << " (expected true)\n";
    std::cout << "inside(3,3)=" << pointInPoly(sq, {3, 3}) << " (expected false)\n";
    return 0;
}
