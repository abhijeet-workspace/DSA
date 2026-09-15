// LC587 Erect the Fence — Andrew monotone chain (include collinear)
#include <algorithm>
#include <iostream>
#include <vector>

using Point = std::vector<int>;

long long cross(const Point& o, const Point& a, const Point& b) {
    return 1LL * (a[0] - o[0]) * (b[1] - o[1]) - 1LL * (a[1] - o[1]) * (b[0] - o[0]);
}

std::vector<Point> outerTrees(std::vector<Point>& trees) {
    int n = static_cast<int>(trees.size());
    if (n <= 1)
        return trees;
    std::sort(trees.begin(), trees.end());
    std::vector<Point> lower, upper;
    for (auto& p : trees) {
        while (lower.size() >= 2 && cross(lower[lower.size() - 2], lower.back(), p) < 0)
            lower.pop_back();
        lower.push_back(p);
    }
    for (int i = n - 1; i >= 0; --i) {
        auto& p = trees[i];
        while (upper.size() >= 2 && cross(upper[upper.size() - 2], upper.back(), p) < 0)
            upper.pop_back();
        upper.push_back(p);
    }
    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    std::sort(lower.begin(), lower.end());
    lower.erase(std::unique(lower.begin(), lower.end()), lower.end());
    return lower;
}

int main() {
    std::vector<Point> trees = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
    auto hull = outerTrees(trees);
    std::cout << "hull_size=" << hull.size() << " (expected 5)\n";
    for (auto& p : hull)
        std::cout << "(" << p[0] << "," << p[1] << ") ";
    std::cout << "\n";
    return 0;
}
