// LC 1288 Remove Covered Intervals
// https://leetcode.com/problems/remove-covered-intervals/
#include <algorithm>
#include <iostream>
#include <vector>
int removeCoveredIntervals(std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    });
    int ans = 0, maxR = -1;
    for (auto& it : intervals)
        if (it[1] > maxR) {
            ++ans;
            maxR = it[1];
        }
    return ans;
}
int main() {
    int a = removeCoveredIntervals({{1, 4}, {3, 6}, {2, 8}});
    int b = removeCoveredIntervals({{1, 4}, {2, 3}});
    bool ok = a == 2 && b == 1;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
