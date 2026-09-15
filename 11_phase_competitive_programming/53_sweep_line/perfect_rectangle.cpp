// LC 391 Perfect Rectangle
// https://leetcode.com/problems/perfect-rectangle/
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <vector>
bool isRectangleCover(std::vector<std::vector<int>> rectangles) {
    long long area = 0;
    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
    std::map<std::pair<int, int>, int> corner;
    auto add = [&](int x, int y) { corner[{x, y}]++; };
    for (auto& r : rectangles) {
        int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
        minX = std::min(minX, x1);
        minY = std::min(minY, y1);
        maxX = std::max(maxX, x2);
        maxY = std::max(maxY, y2);
        area += 1LL * (x2 - x1) * (y2 - y1);
        add(x1, y1);
        add(x1, y2);
        add(x2, y1);
        add(x2, y2);
    }
    if (area != 1LL * (maxX - minX) * (maxY - minY))
        return false;
    std::set<std::pair<int, int>> big = {{minX, minY}, {minX, maxY}, {maxX, minY}, {maxX, maxY}};
    for (auto& [p, c] : corner) {
        if (big.count(p)) {
            if (c != 1)
                return false;
        } else if (c % 2 != 0)
            return false;
    }
    for (auto p : big)
        if (!corner.count(p) || corner[p] != 1)
            return false;
    return true;
}
int main() {
    bool a =
        isRectangleCover({{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}});
    bool b = isRectangleCover({{1, 1, 2, 3}, {1, 3, 2, 4}, {3, 1, 4, 2}, {3, 2, 4, 4}});
    bool ok = a && !b;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
