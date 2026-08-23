// Minimize Max Distance to Gas Station — https://leetcode.com/problems/minimize-max-distance-to-gas-station/
// Add k stations on the line; minimize the maximum gap between adjacent stations.
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

bool canPlace(const std::vector<int>& stations, int k, double dist) {
    int need = 0;
    for (size_t i = 1; i < stations.size(); ++i) {
        const double gap = static_cast<double>(stations[i] - stations[i - 1]);
        need += static_cast<int>(std::ceil(gap / dist) - 1);
        if (need > k) {
            return false;
        }
    }
    return true;
}

double minmaxGasDist(std::vector<int> stations, int k) {
    std::sort(stations.begin(), stations.end());
    double lo = 0.0;
    double hi = static_cast<double>(stations.back() - stations.front());
    for (int it = 0; it < 80; ++it) { // fixed iterations beat epsilon loops
        const double mid = (lo + hi) / 2.0;
        if (canPlace(stations, k, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

int main() {
    std::cout << std::fixed << std::setprecision(5)
              << minmaxGasDist({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 9)
              << " (expected 0.50000)\n";
    return 0;
}
