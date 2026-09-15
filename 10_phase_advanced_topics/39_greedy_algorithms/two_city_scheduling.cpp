// Two City Scheduling — https://leetcode.com/problems/two-city-scheduling/
// Sort by costA-costB; send first n to A, rest to B.
#include <algorithm>
#include <iostream>
#include <vector>

int twoCitySchedCost(std::vector<std::vector<int>> costs) {
    const int n = static_cast<int>(costs.size()) / 2;
    std::sort(costs.begin(), costs.end(), [](const auto& a, const auto& b) {
        return (a[0] - a[1]) < (b[0] - b[1]); // prefer A when A is relatively cheaper
    });
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += costs[static_cast<size_t>(i)][0];
    }
    for (int i = n; i < 2 * n; ++i) {
        total += costs[static_cast<size_t>(i)][1];
    }
    return total;
}

int main() {
    std::cout << twoCitySchedCost({{10, 20}, {30, 200}, {400, 50}, {30, 20}}) << " (expected 110)\n"
              << twoCitySchedCost({{259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469}})
              << " (expected 1859)\n";
    return 0;
}
