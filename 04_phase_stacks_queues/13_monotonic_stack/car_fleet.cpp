// Car Fleet — https://leetcode.com/problems/car-fleet/
// Count fleets that arrive at target (cars cannot pass; catch-up merges).
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    const int n = static_cast<int>(position.size());
    std::vector<std::pair<int, double>> cars;
    cars.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        const double time =
            static_cast<double>(target - position[static_cast<size_t>(i)]) /
            static_cast<double>(speed[static_cast<size_t>(i)]);
        cars.push_back({position[static_cast<size_t>(i)], time});
    }
    std::sort(cars.begin(), cars.end()); // by position ascending
    int fleets = 0;
    double cur = -1.0; // slowest time seen from the front (right)
    for (int i = n - 1; i >= 0; --i) {
        if (cars[static_cast<size_t>(i)].second > cur) {
            ++fleets;
            cur = cars[static_cast<size_t>(i)].second;
        }
    }
    return fleets;
}

int main() {
    std::vector<int> position = {10, 8, 0, 5, 3};
    std::vector<int> speed = {2, 4, 1, 1, 3};
    std::cout << carFleet(12, position, speed) << " (expected 3)\n";
    return 0;
}
