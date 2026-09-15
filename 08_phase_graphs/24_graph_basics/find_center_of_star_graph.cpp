// Find Center of Star Graph — https://leetcode.com/problems/find-center-of-star-graph/
// A star has one center connected to every other node; return the center.
#include <iostream>
#include <vector>

int findCenter(const std::vector<std::vector<int>>& edges) {
    // center appears in both first edges
    const int a = edges[0][0], b = edges[0][1];
    if (edges[1][0] == a || edges[1][1] == a) return a;
    return b;
}

int main() {
    std::cout << findCenter({{1, 2}, {2, 3}, {4, 2}}) << " (expected 2)\n";
    return 0;
}
