// K Closest Points to Origin — https://leetcode.com/problems/k-closest-points-to-origin/
// Return the k points closest to (0,0) by Euclidean distance.
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::vector<int>> kClosest(const std::vector<std::vector<int>>& points, int k) {
    std::priority_queue<std::pair<int, int>> maxHeap; // {dist^2, index}, size ≤ k
    for (int i = 0; i < static_cast<int>(points.size()); ++i) {
        const int x = points[static_cast<size_t>(i)][0];
        const int y = points[static_cast<size_t>(i)][1];
        const int dist = x * x + y * y; // squared distance (monotonic)
        maxHeap.push({dist, i});
        if (static_cast<int>(maxHeap.size()) > k) {
            maxHeap.pop(); // remove farthest among candidates
        }
    }
    std::vector<std::vector<int>> result;
    result.reserve(static_cast<size_t>(k));
    while (!maxHeap.empty()) {
        result.push_back(points[static_cast<size_t>(maxHeap.top().second)]);
        maxHeap.pop();
    }
    return result;
}

int main() {
    const std::vector<std::vector<int>> points = {{1, 3}, {-2, 2}};
    const auto res = kClosest(points, 1);
    std::cout << "[" << res[0][0] << "," << res[0][1] << "] (expected [-2,2])\n";
    return 0;
}
