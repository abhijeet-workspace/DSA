// My Calendar I — https://leetcode.com/problems/my-calendar-i/
// book(start,end): accept iff no overlap; ordered map keyed by start.
#include <iostream>
#include <map>

class MyCalendar {
    std::map<int, int> books_; // start -> end

public:
    bool book(int start, int end) {
        auto it = books_.lower_bound(start); // first start >= start
        if (it != books_.end() && it->first < end) {
            return false; // next interval starts before we end
        }
        if (it != books_.begin()) {
            auto prev = std::prev(it);
            if (prev->second > start) {
                return false; // previous interval ends after we start
            }
        }
        books_[start] = end;
        return true;
    }
};

int main() {
    MyCalendar cal;
    std::cout << std::boolalpha
              << cal.book(10, 20) << " (expected true)\n"
              << cal.book(15, 25) << " (expected false)\n"
              << cal.book(20, 30) << " (expected true)\n";
    return 0;
}
