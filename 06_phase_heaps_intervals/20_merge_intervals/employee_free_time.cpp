// Employee Free Time — https://leetcode.com/problems/employee-free-time/
// Given busy intervals per employee, return common free intervals (gaps in the merged union).
#include <algorithm>
#include <iostream>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};

std::vector<Interval> employeeFreeTime(std::vector<std::vector<Interval>> schedule) {
    std::vector<Interval> all;
    for (auto& emp : schedule) {
        for (auto& iv : emp) {
            all.push_back(iv);
        }
    }
    std::sort(all.begin(), all.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });
    std::vector<Interval> free;
    int end = all[0].end;
    for (size_t i = 1; i < all.size(); ++i) {
        if (all[i].start > end) {
            free.emplace_back(end, all[i].start);
            end = all[i].end;
        } else {
            end = std::max(end, all[i].end);
        }
    }
    return free;
}

int main() {
    std::vector<std::vector<Interval>> schedule = {
        {Interval(1, 2), Interval(5, 6)},
        {Interval(1, 3)},
        {Interval(4, 10)}};
    const auto free = employeeFreeTime(schedule);
    for (const auto& iv : free) {
        std::cout << "[" << iv.start << "," << iv.end << "] ";
    }
    std::cout << "(expected [3,4])\n";
    return 0;
}
