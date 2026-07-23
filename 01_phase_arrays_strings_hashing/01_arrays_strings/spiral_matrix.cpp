// Spiral Matrix — https://leetcode.com/problems/spiral-matrix/
// Return all matrix elements in spiral order (clockwise from top-left).
#include <iostream>
#include <vector>

std::vector<int> spiralOrder(const std::vector<std::vector<int>>& a) {
    std::vector<int> res;
    if (a.empty()) return res;
    int t = 0; // top bound
    int b = static_cast<int>(a.size()) - 1; // bottom
    int l = 0; // left
    int r = static_cast<int>(a[0].size()) - 1; // right
    while (t <= b && l <= r) {
        for (int j = l; j <= r; ++j) // right across top
            res.push_back(a[static_cast<size_t>(t)][static_cast<size_t>(j)]);
        ++t;
        for (int i = t; i <= b; ++i) // down right col
            res.push_back(a[static_cast<size_t>(i)][static_cast<size_t>(r)]);
        --r;
        if (t <= b) { // left across bottom
            for (int j = r; j >= l; --j)
                res.push_back(a[static_cast<size_t>(b)][static_cast<size_t>(j)]);
            --b;
        }
        if (l <= r) { // up left col
            for (int i = b; i >= t; --i)
                res.push_back(a[static_cast<size_t>(i)][static_cast<size_t>(l)]);
            ++l;
        }
    }
    return res;
}

int main() {
    for (int x : spiralOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}))
        std::cout << x << " ";
    std::cout << "(expected 1 2 3 6 9 8 7 4 5)\n";
    return 0;
}
