// Design Circular Deque — https://leetcode.com/problems/design-circular-deque/
// Ring buffer with insert/delete at both ends.
#include <iostream>
#include <vector>

class MyCircularDeque {
    std::vector<int> buf_;
    int head_ = 0;
    int count_ = 0;
    int cap_;

  public:
    explicit MyCircularDeque(int k) : buf_(static_cast<size_t>(k)), cap_(k) {}

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        head_ = (head_ - 1 + cap_) % cap_;
        buf_[static_cast<size_t>(head_)] = value;
        ++count_;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        buf_[static_cast<size_t>((head_ + count_) % cap_)] = value;
        ++count_;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        head_ = (head_ + 1) % cap_;
        --count_;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        --count_;
        return true;
    }

    int getFront() const { return isEmpty() ? -1 : buf_[static_cast<size_t>(head_)]; }

    int getRear() const {
        if (isEmpty()) {
            return -1;
        }
        return buf_[static_cast<size_t>((head_ + count_ - 1) % cap_)];
    }

    bool isEmpty() const { return count_ == 0; }
    bool isFull() const { return count_ == cap_; }
};

int main() {
    MyCircularDeque d(3);
    std::cout << std::boolalpha;
    std::cout << d.insertLast(1) << " (expected true)\n";
    std::cout << d.insertLast(2) << " (expected true)\n";
    std::cout << d.insertFront(3) << " (expected true)\n";
    std::cout << d.insertFront(4) << " (expected false)\n";
    std::cout << d.getRear() << " (expected 2)\n";
    std::cout << d.isFull() << " (expected true)\n";
    std::cout << d.deleteLast() << " (expected true)\n";
    std::cout << d.insertFront(4) << " (expected true)\n";
    std::cout << d.getFront() << " (expected 4)\n";
    return 0;
}
