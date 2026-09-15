// LC 729 My Calendar I
// https://leetcode.com/problems/my-calendar-i/
#include <iostream>
#include <set>
#include <utility>
struct MyCalendar {
    std::set<std::pair<int, int>> books;
    bool book(int start, int end) {
        auto it = books.lower_bound({start, end});
        if (it != books.end() && it->first < end)
            return false;
        if (it != books.begin() && std::prev(it)->second > start)
            return false;
        books.insert({start, end});
        return true;
    }
};
int main() {
    MyCalendar c;
    bool a = c.book(10, 20), b = c.book(15, 25), d = c.book(20, 30);
    bool ok = a && !b && d;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
