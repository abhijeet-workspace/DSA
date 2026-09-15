// LC939 Minimum Area Rectangle (axis-aligned)
#include <climits>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

int minAreaRect(std::vector<std::vector<int>>& points) {
    std::set<std::pair<int, int>> S;
    for (auto& p : points)
        S.insert({p[0], p[1]});
    int ans = INT_MAX;
    int n = static_cast<int>(points.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[j][0], y2 = points[j][1];
            if (x1 == x2 || y1 == y2)
                continue;
            if (S.count({x1, y2}) && S.count({x2, y1})) {
                ans = std::min(ans, std::abs(x1 - x2) * std::abs(y1 - y2));
            }
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int main() {
    std::vector<std::vector<int>> p = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
    std::cout << "minArea=" << minAreaRect(p) << " (expected 4)\n";
    return 0;
}
