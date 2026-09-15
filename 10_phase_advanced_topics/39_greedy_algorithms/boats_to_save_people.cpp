// Boats to Save People — https://leetcode.com/problems/boats-to-save-people/
// Sort + two pointers: heaviest with lightest if they fit.
#include <algorithm>
#include <iostream>
#include <vector>

int numRescueBoats(std::vector<int> people, int limit) {
    std::sort(people.begin(), people.end());
    int lo = 0;
    int hi = static_cast<int>(people.size()) - 1;
    int boats = 0;
    while (lo <= hi) {
        if (people[static_cast<size_t>(lo)] + people[static_cast<size_t>(hi)] <= limit) {
            ++lo; // pair lightest with heaviest
        }
        --hi;
        ++boats;
    }
    return boats;
}

int main() {
    std::cout << numRescueBoats({1, 2}, 3) << " (expected 1)\n"
              << numRescueBoats({3, 2, 2, 1}, 3) << " (expected 3)\n"
              << numRescueBoats({3, 5, 3, 4}, 5) << " (expected 4)\n";
    return 0;
}
