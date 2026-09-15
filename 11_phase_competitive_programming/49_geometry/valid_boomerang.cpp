// LC1037 Valid Boomerang
#include <iostream>
#include <vector>

bool isBoomerang(std::vector<std::vector<int>>& points) {
    long long x1 = points[0][0], y1 = points[0][1];
    long long x2 = points[1][0], y2 = points[1][1];
    long long x3 = points[2][0], y3 = points[2][1];
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) != 0;
}

int main() {
    std::vector<std::vector<int>> a = {{1, 1}, {2, 3}, {3, 2}};
    std::vector<std::vector<int>> b = {{1, 1}, {2, 2}, {3, 3}};
    std::cout << std::boolalpha;
    std::cout << "boomerang A=" << isBoomerang(a) << " (expected true)\n";
    std::cout << "boomerang B=" << isBoomerang(b) << " (expected false)\n";
    return 0;
}
