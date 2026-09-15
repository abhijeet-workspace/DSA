// Minimum Operations to Halve Array Sum — https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
// Max-heap of doubles; repeatedly halve largest until sum <= half initial.
#include <iostream>
#include <queue>
#include <vector>

int halveArray(std::vector<int>& nums) {
    std::priority_queue<double> maxHeap;
    double sum = 0;
    for (int x : nums) {
        maxHeap.push(static_cast<double>(x));
        sum += x;
    }
    const double target = sum / 2.0;
    double reduced = 0;
    int ops = 0;
    while (reduced < target) {
        double x = maxHeap.top();
        maxHeap.pop();
        reduced += x / 2.0;
        maxHeap.push(x / 2.0);
        ++ops;
    }
    return ops;
}

int main() {
    std::vector<int> nums = {5, 19, 8, 1};
    std::cout << halveArray(nums) << " (expected 3)\n";
    return 0;
}
