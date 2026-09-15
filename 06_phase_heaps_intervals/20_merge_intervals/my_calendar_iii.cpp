// My Calendar III — https://leetcode.com/problems/my-calendar-iii/
// Ordered map delta sweep; track max concurrent bookings (k-booking).
#include <iostream>
#include <map>

class MyCalendarThree {
    std::map<int, int> delta;
    int maxK = 0;

public:
    int book(int start, int end) {
        delta[start] += 1;
        delta[end] -= 1;
        int cur = 0;
        maxK = 0;
        for (auto& [t, d] : delta) {
            cur += d;
            maxK = std::max(maxK, cur);
        }
        return maxK;
    }
};

int main() {
    MyCalendarThree cal;
    std::cout << cal.book(10, 20) << " (expected 1)\n";
    std::cout << cal.book(50, 60) << " (expected 1)\n";
    std::cout << cal.book(10, 40) << " (expected 2)\n";
    std::cout << cal.book(5, 15) << " (expected 3)\n";
    std::cout << cal.book(5, 10) << " (expected 3)\n";
    std::cout << cal.book(25, 55) << " (expected 3)\n";
    return 0;
}
