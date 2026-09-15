// My Calendar III — https://leetcode.com/problems/my-calendar-iii/
// Difference map +1 start / -1 end; scan for max concurrent.
#include <iostream>
#include <map>

class MyCalendarThree {
    std::map<int, int> diff;

public:
    int book(int start, int end) {
        ++diff[start];
        --diff[end];
        int cur = 0, best = 0;
        for (auto& [_, d] : diff) {
            cur += d;
            best = std::max(best, cur);
        }
        return best;
    }
};

int main() {
    MyCalendarThree c;
    std::cout << c.book(10, 20) << " (expected 1)\n"
              << c.book(50, 60) << " (expected 1)\n"
              << c.book(10, 40) << " (expected 2)\n"
              << c.book(5, 15) << " (expected 3)\n"
              << c.book(5, 10) << " (expected 3)\n"
              << c.book(25, 55) << " (expected 3)\n";
    return 0;
}
