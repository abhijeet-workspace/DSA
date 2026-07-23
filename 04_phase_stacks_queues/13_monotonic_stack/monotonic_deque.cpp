// MaxQueue via monotonic deque — O(1) amortized push/pop, O(1) getMax.
#include <deque>
#include <iostream>
#include <queue>
#include <stdexcept>

class MaxQueue {
    std::queue<int> q;
    std::deque<int> max_dq; // decreasing values; front = current max

public:
    void push(int val) {
        q.push(val);
        while (!max_dq.empty() && max_dq.back() < val) {
            max_dq.pop_back();
        }
        max_dq.push_back(val);
    }

    void pop() {
        if (q.empty()) {
            return;
        }
        const int val = q.front();
        q.pop();
        if (!max_dq.empty() && val == max_dq.front()) {
            max_dq.pop_front();
        }
    }

    int getMax() const {
        if (max_dq.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return max_dq.front();
    }

    bool empty() const { return q.empty(); }
};

int main() {
    MaxQueue mq;
    mq.push(4);
    mq.push(1);
    mq.push(3);
    mq.push(2);
    std::cout << "Max after pushes: " << mq.getMax() << " (expected 4)\n";
    mq.pop(); // remove 4
    std::cout << "Max after pop 4: " << mq.getMax() << " (expected 3)\n";
    mq.pop(); // remove 1
    mq.pop(); // remove 3
    std::cout << "Max after pop to 2: " << mq.getMax() << " (expected 2)\n";
    return 0;
}
