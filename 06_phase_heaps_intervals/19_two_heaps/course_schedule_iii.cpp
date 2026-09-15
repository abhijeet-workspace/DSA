// Course Schedule III — https://leetcode.com/problems/course-schedule-iii/
// Sort by deadline; max-heap of taken durations; drop longest if overdue.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int scheduleCourse(std::vector<std::vector<int>>& courses) {
    std::sort(courses.begin(), courses.end(),
              [](const auto& a, const auto& b) { return a[1] < b[1]; });
    std::priority_queue<int> taken; // durations
    int time = 0;
    for (const auto& c : courses) {
        int dur = c[0], last = c[1];
        if (time + dur <= last) {
            taken.push(dur);
            time += dur;
        } else if (!taken.empty() && taken.top() > dur) {
            time += dur - taken.top();
            taken.pop();
            taken.push(dur);
        }
    }
    return static_cast<int>(taken.size());
}

int main() {
    std::vector<std::vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    std::cout << scheduleCourse(courses) << " (expected 3)\n";
    return 0;
}
