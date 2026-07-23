// Min Stack — https://leetcode.com/problems/min-stack/
// Store deltas vs running min so getMin/top/pop are O(1).
#include <iostream>
#include <stack>

class MinStack {
    std::stack<long long> st_;
    long long mn_ = 0;

public:
    void push(int val) {
        if (st_.empty()) {
            st_.push(0);
            mn_ = val;
            return;
        }
        st_.push(static_cast<long long>(val) - mn_);
        if (val < mn_) {
            mn_ = val;
        }
    }

    void pop() {
        const long long t = st_.top();
        st_.pop();
        if (t < 0) {
            mn_ = mn_ - t; // restore previous min
        }
    }

    int top() const {
        const long long t = st_.top();
        return static_cast<int>(t < 0 ? mn_ : mn_ + t);
    }

    int getMin() const { return static_cast<int>(mn_); }
};

int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    std::cout << s.getMin() << " (expected -3)\n";
    s.pop();
    std::cout << s.top() << " (expected 0)\n";
    std::cout << s.getMin() << " (expected -2)\n";
    return 0;
}
