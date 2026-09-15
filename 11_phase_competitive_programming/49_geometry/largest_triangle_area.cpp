// LC812 Largest Triangle Area
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

double largestTriangleArea(std::vector<std::vector<int>>& points) {
    double ans = 0;
    int n = static_cast<int>(points.size());
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k) {
                double x1 = points[i][0], y1 = points[i][1];
                double x2 = points[j][0], y2 = points[j][1];
                double x3 = points[k][0], y3 = points[k][1];
                double a = std::fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
                ans = std::max(ans, a);
            }
    return ans;
}

int main() {
    std::vector<std::vector<int>> p = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "area=" << largestTriangleArea(p) << " (expected 2.00000)\n";
    return 0;
}
