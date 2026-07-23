// Meeting Rooms II — https://leetcode.com/problems/meeting-rooms-ii/
// Minimum conference rooms required for all meetings.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }
    std::sort(intervals.begin(), intervals.end()); // by start
    std::priority_queue<int, std::vector<int>, std::greater<int>> ends; // min-heap of ends
    ends.push(intervals[0][1]);
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] >= ends.top()) { // reuse earliest room
            ends.pop();
        }
        ends.push(intervals[i][1]);
    }
    return static_cast<int>(ends.size());
}

int main() {
    std::vector<std::vector<int>> a = {{0, 30}, {5, 10}, {15, 20}};
    std::vector<std::vector<int>> b = {{7, 10}, {2, 4}};
    std::cout << minMeetingRooms(a) << " (expected 2)\n"
              << minMeetingRooms(b) << " (expected 1)\n";
    return 0;
}
