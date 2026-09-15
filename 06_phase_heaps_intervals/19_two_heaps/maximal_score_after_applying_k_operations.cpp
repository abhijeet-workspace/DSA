// Maximal Score After Applying K Operations —
// https://leetcode.com/problems/maximal-score-after-applying-k-operations/ Max-heap: score += x,
// replace with ceil(x/3), k times.
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

long long maxKelements(std::vector<int>& nums, int k) {
    std::priority_queue<int> maxHeap(nums.begin(), nums.end());
    long long score = 0;
    while (k--) {
        int x = maxHeap.top();
        maxHeap.pop();
        score += x;
        maxHeap.push((x + 2) / 3); // ceil(x/3)
    }
    return score;
}

int main() {
    std::vector<int> nums = {1, 10, 3, 3, 3};
    std::cout << maxKelements(nums, 3) << " (expected 17)\n";
    return 0;
}
