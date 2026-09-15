// Design Circular Queue — https://leetcode.com/problems/design-circular-queue/
// Fixed ring buffer: head index + count.
#include <iostream>
#include <vector>

class MyCircularQueue {
    std::vector<int> buf_;
    int head_ = 0;
    int count_ = 0;
    int cap_;

  public:
    explicit MyCircularQueue(int k) : buf_(static_cast<size_t>(k)), cap_(k) {}

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        buf_[static_cast<size_t>((head_ + count_) % cap_)] = value;
        ++count_;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head_ = (head_ + 1) % cap_;
        --count_;
        return true;
    }

    int Front() const { return isEmpty() ? -1 : buf_[static_cast<size_t>(head_)]; }

    int Rear() const {
        if (isEmpty()) {
            return -1;
        }
        return buf_[static_cast<size_t>((head_ + count_ - 1) % cap_)];
    }

    bool isEmpty() const { return count_ == 0; }
    bool isFull() const { return count_ == cap_; }
};

int main() {
    MyCircularQueue q(3);
    std::cout << std::boolalpha;
    std::cout << q.enQueue(1) << " (expected true)\n";
    std::cout << q.enQueue(2) << " (expected true)\n";
    std::cout << q.enQueue(3) << " (expected true)\n";
    std::cout << q.enQueue(4) << " (expected false)\n";
    std::cout << q.Rear() << " (expected 3)\n";
    std::cout << q.isFull() << " (expected true)\n";
    std::cout << q.deQueue() << " (expected true)\n";
    std::cout << q.enQueue(4) << " (expected true)\n";
    std::cout << q.Rear() << " (expected 4)\n";
    return 0;
}
