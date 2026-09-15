// Implement Stack using Queues — https://leetcode.com/problems/implement-stack-using-queues/
// One queue: on push, enqueue then rotate so front is always top.
#include <iostream>
#include <queue>

class MyStack {
    std::queue<int> q_;

  public:
    void push(int x) {
        q_.push(x);
        const int n = static_cast<int>(q_.size());
        for (int i = 0; i < n - 1; ++i) { // rotate older elements behind x
            q_.push(q_.front());
            q_.pop();
        }
    }

    int pop() {
        const int val = q_.front();
        q_.pop();
        return val;
    }

    int top() const { return q_.front(); }

    bool empty() const { return q_.empty(); }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    std::cout << "Top: " << s.top() << " (expected 2)\n";
    std::cout << "Popped: " << s.pop() << " (expected 2)\n";
    std::cout << "Empty? " << (s.empty() ? "yes" : "no") << " (expected no)\n";
    return 0;
}
