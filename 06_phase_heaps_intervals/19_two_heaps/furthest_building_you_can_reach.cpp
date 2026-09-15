// Furthest Building You Can Reach — https://leetcode.com/problems/furthest-building-you-can-reach/
// Assign ladders to largest climbs via min-heap; bricks cover the rest.
#include <iostream>
#include <queue>
#include <vector>

int furthestBuilding(const std::vector<int>& heights, int bricks, int ladders) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> ladderClimbs;
    long long brickUsed = 0;
    for (int i = 0; i + 1 < static_cast<int>(heights.size()); ++i) {
        const int diff = heights[static_cast<size_t>(i + 1)] - heights[static_cast<size_t>(i)];
        if (diff <= 0) {
            continue;
        }
        ladderClimbs.push(diff);
        if (static_cast<int>(ladderClimbs.size()) > ladders) {
            brickUsed += ladderClimbs.top();
            ladderClimbs.pop();
        }
        if (brickUsed > bricks) {
            return i;
        }
    }
    return static_cast<int>(heights.size()) - 1;
}

int main() {
    std::cout << furthestBuilding({4, 2, 7, 6, 9, 14, 12}, 5, 1) << " (expected 4)\n"
              << furthestBuilding({4, 12, 2, 7, 3, 18, 20, 3, 19}, 10, 2) << " (expected 7)\n";
    return 0;
}
