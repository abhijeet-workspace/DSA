// Search a 2D Matrix — https://leetcode.com/problems/search-a-2d-matrix/
// Row-wise sorted matrix treated as a flat sorted array; binary search.
#include <iostream>
#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& a, int target) {
    if (a.empty() || a[0].empty()) {
        return false;
    }
    const int m = static_cast<int>(a.size());
    const int n = static_cast<int>(a[0].size());
    int lo = 0;
    int hi = m * n - 1;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        const int v = a[static_cast<size_t>(mid / n)][static_cast<size_t>(mid % n)];
        if (v == target) {
            return true;
        }
        if (v < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return false;
}

int main() {
    const std::vector<std::vector<int>> a = {{1, 3, 5}, {7, 9, 11}};
    std::cout << std::boolalpha << searchMatrix(a, 9) << " (expected true)\n";
    return 0;
}
