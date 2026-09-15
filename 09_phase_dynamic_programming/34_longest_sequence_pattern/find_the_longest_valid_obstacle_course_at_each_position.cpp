// Find the Longest Valid Obstacle Course at Each Position — https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> longestObstacleCourseAtEachPosition(std::vector<int>& obstacles) {
    std::vector<int> tails, ans;
    ans.reserve(obstacles.size());
    for (int x : obstacles) {
        auto it = std::upper_bound(tails.begin(), tails.end(), x);
        const int pos = static_cast<int>(it - tails.begin());
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
        ans.push_back(pos + 1);
    }
    return ans;
}

int main() {
    std::vector<int> o{1, 2, 3, 2};
    for (int x : longestObstacleCourseAtEachPosition(o)) std::cout << x << ' ';
    std::cout << "(expected 1 2 3 3)\n";
    return 0;
}
