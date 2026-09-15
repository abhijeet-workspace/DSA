// Triangle — https://leetcode.com/problems/triangle/
#include <algorithm>
#include <iostream>
#include <vector>

int minimumTotal(std::vector<std::vector<int>>& triangle) {
    for (int r = static_cast<int>(triangle.size()) - 2; r >= 0; --r) {
        for (int c = 0; c <= r; ++c) {
            triangle[static_cast<size_t>(r)][static_cast<size_t>(c)] +=
                std::min(triangle[static_cast<size_t>(r + 1)][static_cast<size_t>(c)],
                         triangle[static_cast<size_t>(r + 1)][static_cast<size_t>(c + 1)]);
        }
    }
    return triangle[0][0];
}

int main() {
    std::vector<std::vector<int>> t{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    std::cout << minimumTotal(t) << " (expected 11)\n";
    return 0;
}
