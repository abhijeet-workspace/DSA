// Design Hit Counter — https://leetcode.com/problems/design-hit-counter/
// Count hits in the past 300 seconds; hit(timestamp) and getHits(timestamp).
#include <deque>
#include <iostream>
#include <utility>

class HitCounter {
    std::deque<std::pair<int, int>> q_; // timestamp, count
    int total_ = 0;

    void evict(int timestamp) {
        while (!q_.empty() && timestamp - q_.front().first >= 300) {
            total_ -= q_.front().second;
            q_.pop_front();
        }
    }

  public:
    void hit(int timestamp) {
        evict(timestamp);
        if (!q_.empty() && q_.back().first == timestamp) {
            ++q_.back().second;
        } else {
            q_.push_back({timestamp, 1});
        }
        ++total_;
    }

    int getHits(int timestamp) {
        evict(timestamp);
        return total_;
    }
};

int main() {
    HitCounter counter;
    counter.hit(1);
    counter.hit(2);
    counter.hit(3);
    std::cout << counter.getHits(4) << " (expected 3)\n";
    counter.hit(300);
    std::cout << counter.getHits(300) << " (expected 4)\n";
    std::cout << counter.getHits(301) << " (expected 3)\n";
    return 0;
}
