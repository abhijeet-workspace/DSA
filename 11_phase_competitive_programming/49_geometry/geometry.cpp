// Computational geometry — orientation, Graham hull, segment intersect
// Hull O(N log N); orientation/intersect O(1)
#include <algorithm>
#include <iostream>
#include <vector>

struct Point {
    int x, y;
    bool operator<(const Point& o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
};

// 0 collinear, 1 clockwise, 2 counterclockwise
int orientation(Point p, Point q, Point r) {
    long long val = 1LL * (q.y - p.y) * (r.x - q.x) - 1LL * (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return val > 0 ? 1 : 2;
}

int dist_sq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point pivot;

bool polar_less(Point a, Point b) {
    int o = orientation(pivot, a, b);
    if (o == 0) return dist_sq(pivot, a) < dist_sq(pivot, b);
    return o == 2;
}

std::vector<Point> convex_hull(std::vector<Point> points) {
    int n = static_cast<int>(points.size());
    if (n < 3) return {};

    int ymin = points[0].y, mini = 0;
    for (int i = 1; i < n; ++i) {
        if (points[i].y < ymin || (points[i].y == ymin && points[i].x < points[mini].x)) {
            ymin = points[i].y;
            mini = i;
        }
    }
    std::swap(points[0], points[mini]);
    pivot = points[0];
    std::sort(points.begin() + 1, points.end(), polar_less);

    int m = 1;
    for (int i = 1; i < n; ++i) {
        while (i < n - 1 && orientation(pivot, points[i], points[i + 1]) == 0) ++i;
        points[m++] = points[i];
    }
    if (m < 3) return {};

    std::vector<Point> hull = {points[0], points[1], points[2]};
    for (int i = 3; i < m; ++i) {
        while (hull.size() >= 2 &&
               orientation(hull[hull.size() - 2], hull.back(), points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    return hull;
}

bool on_segment(Point p, Point q, Point r) {
    return q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
           q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y);
}

bool segments_intersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && on_segment(p1, p2, q1)) return true;
    if (o2 == 0 && on_segment(p1, q2, q1)) return true;
    if (o3 == 0 && on_segment(p2, p1, q2)) return true;
    if (o4 == 0 && on_segment(p2, q1, q2)) return true;
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<Point> pts = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    auto hull = convex_hull(pts);
    std::cout << "Hull:";
    for (auto p : hull) std::cout << " (" << p.x << "," << p.y << ")";
    std::cout << "\n";

    Point a{1, 1}, b{10, 1}, c{1, 2}, d{10, 2};
    std::cout << "Parallel segments intersect? "
              << (segments_intersect(a, b, c, d) ? "YES" : "NO") << " (expected NO)\n";
    return 0;
}
