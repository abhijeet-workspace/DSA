// Smallest Range Covering Elements from K Lists —
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ Min-heap of current
// heads + track max; advance the list of the min.
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>

std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
    using T = std::tuple<int, int, int>; // val, listIdx, elemIdx
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    int curMax = std::numeric_limits<int>::min();
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        pq.push({nums[static_cast<size_t>(i)][0], i, 0});
        curMax = std::max(curMax, nums[static_cast<size_t>(i)][0]);
    }
    int bestL = 0, bestR = std::numeric_limits<int>::max();
    while (true) {
        auto [val, li, ei] = pq.top();
        pq.pop();
        if (curMax - val < bestR - bestL) {
            bestL = val;
            bestR = curMax;
        }
        if (ei + 1 == static_cast<int>(nums[static_cast<size_t>(li)].size()))
            break;
        int nxt = nums[static_cast<size_t>(li)][static_cast<size_t>(ei + 1)];
        pq.push({nxt, li, ei + 1});
        curMax = std::max(curMax, nxt);
    }
    return {bestL, bestR};
}

int main() {
    std::vector<std::vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    auto r = smallestRange(nums);
    std::cout << r[0] << " " << r[1] << " (expected 20 24)\n";
    return 0;
}
