// Gas Station — https://leetcode.com/problems/gas-station/
// If total gas >= cost, unique start exists; reset tank when negative.
#include <iostream>
#include <vector>

int canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < static_cast<int>(gas.size()); ++i) {
        const int d = gas[static_cast<size_t>(i)] - cost[static_cast<size_t>(i)];
        total += d;
        tank += d;
        if (tank < 0) { // cannot start at or before i
            start = i + 1;
            tank = 0;
        }
    }
    return total >= 0 ? start : -1;
}

int main() {
    const std::vector<int> g = {1, 2, 3, 4, 5};
    const std::vector<int> c = {3, 4, 5, 1, 2};
    std::cout << canCompleteCircuit(g, c) << " (expected 3)\n";
    return 0;
}
