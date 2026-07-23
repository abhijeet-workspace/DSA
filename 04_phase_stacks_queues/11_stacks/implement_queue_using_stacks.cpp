// Implement Queue using Stacks — https://leetcode.com/problems/implement-queue-using-stacks/
// Two stacks: input for push, output for pop/peek (amortized O(1)).
#include <iostream>
#include <stack>

class MyQueue {
    std::stack<int> in_;
    std::stack<int> out_;

    void transfer() {
        if (out_.empty()) {
            while (!in_.empty()) {
                out_.push(in_.top());
                in_.pop();
            }
        }
    }

public:
    void push(int x) { in_.push(x); }

    int pop() {
        transfer();
        const int val = out_.top();
        out_.pop();
        return val;
    }

    int peek() {
        transfer();
        return out_.top();
    }

    bool empty() const { return in_.empty() && out_.empty(); }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    std::cout << "Front: " << q.peek() << " (expected 1)\n";
    std::cout << "Popped: " << q.pop() << " (expected 1)\n";
    std::cout << "Empty? " << (q.empty() ? "yes" : "no") << " (expected no)\n";
    return 0;
}
