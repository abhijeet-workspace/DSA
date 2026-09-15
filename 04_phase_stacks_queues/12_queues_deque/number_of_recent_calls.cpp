// Number of Recent Calls — https://leetcode.com/problems/number-of-recent-calls/
// Count pings in [t-3000, t]; queue drops expired front.
#include <iostream>
#include <queue>

class RecentCounter {
    std::queue<int> q_;

  public:
    int ping(int t) {
        q_.push(t);
        while (!q_.empty() && q_.front() < t - 3000) {
            q_.pop();
        }
        return static_cast<int>(q_.size());
    }
};

int main() {
    RecentCounter rc;
    std::cout << rc.ping(1) << " (expected 1)\n";
    std::cout << rc.ping(100) << " (expected 2)\n";
    std::cout << rc.ping(3001) << " (expected 3)\n";
    std::cout << rc.ping(3002) << " (expected 3)\n";
    return 0;
}
