// Meeting Rooms — https://leetcode.com/problems/meeting-rooms/
// Return true if a person can attend all meetings (no overlaps).
#include <algorithm>
#include <iostream>
#include <vector>

bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end()); // by start
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < intervals[i - 1][1]) { // overlap
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> a = {{0, 30}, {5, 10}, {15, 20}};
    std::vector<std::vector<int>> b = {{7, 10}, {2, 4}};
    std::cout << std::boolalpha << canAttendMeetings(a) << " (expected false)\n"
              << canAttendMeetings(b) << " (expected true)\n";
    return 0;
}
