// My Calendar II — https://leetcode.com/problems/my-calendar-ii/
// Track bookings + overlaps; reject if would create triple booking.
#include <iostream>
#include <vector>

class MyCalendarTwo {
    std::vector<std::pair<int, int>> booked;
    std::vector<std::pair<int, int>> overlaps;

    static bool intersects(int s1, int e1, int s2, int e2) {
        return s1 < e2 && s2 < e1;
    }

public:
    bool book(int start, int end) {
        for (auto [os, oe] : overlaps) {
            if (intersects(start, end, os, oe)) return false; // would be triple
        }
        for (auto [bs, be] : booked) {
            if (intersects(start, end, bs, be)) {
                overlaps.push_back({std::max(start, bs), std::min(end, be)});
            }
        }
        booked.push_back({start, end});
        return true;
    }
};

int main() {
    MyCalendarTwo cal;
    std::cout << std::boolalpha
              << cal.book(10, 20) << " (expected true)\n"
              << cal.book(50, 60) << " (expected true)\n"
              << cal.book(10, 40) << " (expected true)\n"
              << cal.book(5, 15) << " (expected false)\n"
              << cal.book(5, 10) << " (expected true)\n"
              << cal.book(25, 55) << " (expected true)\n";
    return 0;
}
