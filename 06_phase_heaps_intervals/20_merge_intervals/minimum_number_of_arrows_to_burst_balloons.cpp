// Minimum Number of Arrows to Burst Balloons —
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/ Sort by end; shoot at
// end; skip balloons covering that point.
#include <algorithm>
#include <iostream>
#include <vector>

int findMinArrowShots(std::vector<std::vector<int>>& points) {
    if (points.empty())
        return 0;
    std::sort(points.begin(), points.end(),
              [](const auto& a, const auto& b) { return a[1] < b[1]; });
    int arrows = 1;
    int end = points[0][1];
    for (size_t i = 1; i < points.size(); ++i) {
        if (points[i][0] > end) {
            ++arrows;
            end = points[i][1];
        }
    }
    return arrows;
}

int main() {
    std::vector<std::vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    std::cout << findMinArrowShots(points) << " (expected 2)\n";
    return 0;
}
