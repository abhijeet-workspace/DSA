// Rotate Image — https://leetcode.com/problems/rotate-image/
// Rotate n x n matrix 90° clockwise in-place.
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void rotate(std::vector<std::vector<int>>& a) {
    const int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i) { // transpose
        for (int j = i + 1; j < n; ++j) {
            std::swap(a[static_cast<size_t>(i)][static_cast<size_t>(j)],
                      a[static_cast<size_t>(j)][static_cast<size_t>(i)]);
        }
    }
    for (auto& row : a) { // reverse each row
        std::reverse(row.begin(), row.end());
    }
}

int main() {
    std::vector<std::vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(a);
    for (const auto& r : a) {
        for (int x : r) std::cout << x << " ";
        std::cout << "\n";
    }
    // expected: 7 4 1 / 8 5 2 / 9 6 3
    return 0;
}
