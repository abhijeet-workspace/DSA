// Interval List Intersections — https://leetcode.com/problems/interval-list-intersections/
// Two sorted disjoint lists: two pointers, emit overlap when ranges intersect.
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>>
intervalIntersection(const std::vector<std::vector<int>>& firstList,
                     const std::vector<std::vector<int>>& secondList) {
    std::vector<std::vector<int>> result;
    size_t i = 0;
    size_t j = 0;
    while (i < firstList.size() && j < secondList.size()) {
        const int lo = std::max(firstList[i][0], secondList[j][0]);
        const int hi = std::min(firstList[i][1], secondList[j][1]);
        if (lo <= hi) {
            result.push_back({lo, hi}); // non-empty intersection
        }
        if (firstList[i][1] < secondList[j][1]) {
            ++i; // advance the interval that ends first
        } else {
            ++j;
        }
    }
    return result;
}

int main() {
    const auto r = intervalIntersection({{0, 2}, {5, 10}, {13, 23}, {24, 25}},
                                        {{1, 5}, {8, 12}, {15, 24}, {25, 26}});
    for (const auto& x : r) {
        std::cout << "[" << x[0] << "," << x[1] << "] ";
    }
    std::cout << "(expected [1,2] [5,5] [8,10] [15,23] [24,24] [25,25])\n";
    return 0;
}
