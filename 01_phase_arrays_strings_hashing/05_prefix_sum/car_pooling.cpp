// Car Pooling — https://leetcode.com/problems/car-pooling/
// Can capacity never be exceeded given trips [numPassengers, from, to]?
#include <iostream>
#include <vector>

bool carPooling(const std::vector<std::vector<int>>& trips, int capacity) {
    std::vector<int> diff(1001, 0); // stop -> delta passengers (LC constraint)
    for (const auto& trip : trips) {
        int passengers = trip[0];
        int from = trip[1];
        int to = trip[2];
        diff[from] += passengers; // pick up
        diff[to] -= passengers;   // drop off at `to` (exclusive of ride)
    }
    int current = 0;
    for (int stop = 0; stop <= 1000; ++stop) {
        current += diff[stop]; // running load
        if (current > capacity) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
    std::cout << (carPooling(trips, 4) ? "true" : "false") << " (expected false)\n";
    std::cout << (carPooling(trips, 5) ? "true" : "false") << " (expected true)\n";
    return 0;
}
