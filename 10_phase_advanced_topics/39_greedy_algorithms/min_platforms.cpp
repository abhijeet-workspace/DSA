// Min Platforms — classic interval overlap / Meeting Rooms II
// Sort arrivals & departures; sweep concurrent trains.
#include <iostream>
#include <vector>
#include <algorithm>

int minPlatforms(std::vector<int> arrival, std::vector<int> departure) {
    std::sort(arrival.begin(), arrival.end());
    std::sort(departure.begin(), departure.end());
    int i = 0, j = 0, cur = 0, best = 0;
    while (i < static_cast<int>(arrival.size()) && j < static_cast<int>(departure.size())) {
        if (arrival[static_cast<size_t>(i)] <= departure[static_cast<size_t>(j)]) {
            ++cur; // train arrives
            best = std::max(best, cur);
            ++i;
        } else {
            --cur; // train departs
            ++j;
        }
    }
    return best;
}

int main() {
    std::cout << minPlatforms({900, 940, 950, 1100, 1500, 1800},
                              {910, 1200, 1120, 1130, 1900, 2000})
              << " (expected 3)\n";
    return 0;
}
