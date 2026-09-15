// LC149 Max Points on a Line
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

int maxPoints(std::vector<std::vector<int>>& points) {
    int n = static_cast<int>(points.size());
    if (n <= 2)
        return n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        std::map<std::pair<int, int>, int> slope;
        int dup = 0, local = 0;
        for (int j = i + 1; j < n; ++j) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            if (dx == 0 && dy == 0) {
                ++dup;
                continue;
            }
            int g = std::gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            } else if (dx == 0 && dy < 0)
                dy = -dy;
            local = std::max(local, ++slope[{dx, dy}]);
        }
        ans = std::max(ans, local + dup + 1);
    }
    return ans;
}

int main() {
    std::vector<std::vector<int>> p = {{1, 1}, {2, 2}, {3, 3}};
    std::cout << "maxPoints=" << maxPoints(p) << " (expected 3)\n";
    std::vector<std::vector<int>> q = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    std::cout << "maxPoints2=" << maxPoints(q) << " (expected 4)\n";
    return 0;
}
