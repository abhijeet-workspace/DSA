// Kth Largest Element in a Stream — https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Min-heap of size k: top is always the kth largest.
#include <iostream>
#include <queue>
#include <vector>

class KthLargest {
    int k_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_;

    void push(int val) {
        min_heap_.push(val);
        if (static_cast<int>(min_heap_.size()) > k_) {
            min_heap_.pop(); // drop smallest outside top-k window
        }
    }

  public:
    KthLargest(int k, const std::vector<int>& nums) : k_(k) {
        for (int x : nums) {
            push(x);
        }
    }

    int add(int val) {
        push(val);
        return min_heap_.top();
    }
};

int main() {
    KthLargest kth(3, {4, 5, 8, 2});
    std::cout << kth.add(3) << " (expected 4)\n";
    std::cout << kth.add(5) << " (expected 5)\n";
    std::cout << kth.add(10) << " (expected 5)\n";
    std::cout << kth.add(9) << " (expected 8)\n";
    std::cout << kth.add(4) << " (expected 8)\n";
    return 0;
}
