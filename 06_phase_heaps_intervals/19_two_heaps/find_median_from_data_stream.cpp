// Find Median from Data Stream — https://leetcode.com/problems/find-median-from-data-stream/
// Stream of ints; addNum + findMedian via two balanced heaps.
#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
    std::priority_queue<int> low; // max-heap: lower half
    std::priority_queue<int, std::vector<int>, std::greater<int>> high; // min-heap: upper

public:
    void addNum(int num) {
        low.push(num);
        high.push(low.top()); // move largest of low into high
        low.pop();
        if (low.size() < high.size()) { // keep low >= high
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian() const {
        if (low.size() > high.size()) {
            return static_cast<double>(low.top()); // odd count
        }
        return (low.top() + high.top()) / 2.0; // even: average tops
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    std::cout << mf.findMedian() << " (expected 1.5)\n";
    mf.addNum(3);
    std::cout << mf.findMedian() << " (expected 2)\n";
    return 0;
}
