// Moving Average from Data Stream — https://leetcode.com/problems/moving-average-from-data-stream/
// Queue of last `size` values + running sum.
#include <iostream>
#include <queue>

class MovingAverage {
    int size_;
    long long sum_ = 0;
    std::queue<int> q_;

  public:
    explicit MovingAverage(int size) : size_(size) {}

    double next(int val) {
        if (static_cast<int>(q_.size()) == size_) {
            sum_ -= q_.front();
            q_.pop();
        }
        q_.push(val);
        sum_ += val;
        return static_cast<double>(sum_) / static_cast<double>(q_.size());
    }
};

int main() {
    MovingAverage m(3);
    std::cout << m.next(1) << " (expected 1)\n";
    std::cout << m.next(10) << " (expected 5.5)\n";
    std::cout << m.next(3) << " (expected 4.66667)\n";
    std::cout << m.next(5) << " (expected 6)\n";
    return 0;
}
