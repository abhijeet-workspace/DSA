// deque — STL double-ended queue
// Efficient push/pop at both ends; contrast with vector front operations.
#include <deque>
#include <iostream>

static void print_dq(const std::deque<int>& d, const char* name) {
    std::cout << name << ':';
    for (int x : d) {
        std::cout << ' ' << x;
    }
    std::cout << " (size=" << d.size() << ")\n";
}

int main() {
    std::deque<int> d;
    d.push_back(20);
    d.push_back(30);
    d.push_front(10);
    print_dq(d, "after pushes"); // 10 20 30

    std::cout << "front=" << d.front() << " back=" << d.back() << '\n';
    std::cout << "d[1]=" << d[1] << '\n'; // random-access

    d.pop_front();
    d.pop_back();
    print_dq(d, "after pops"); // 20

    d.insert(d.begin() + 1, 99); // middle insert (may be costly)
    print_dq(d, "after insert");

    return 0;
}
