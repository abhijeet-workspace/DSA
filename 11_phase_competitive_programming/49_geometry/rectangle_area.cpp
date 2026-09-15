// LC223 Rectangle Area
#include <algorithm>
#include <iostream>

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    long long areaA = 1LL * (ax2 - ax1) * (ay2 - ay1);
    long long areaB = 1LL * (bx2 - bx1) * (by2 - by1);
    int overlapX = std::max(0, std::min(ax2, bx2) - std::max(ax1, bx1));
    int overlapY = std::max(0, std::min(ay2, by2) - std::max(ay1, by1));
    return static_cast<int>(areaA + areaB - 1LL * overlapX * overlapY);
}

int main() {
    std::cout << "area=" << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << " (expected 45)\n";
    return 0;
}
