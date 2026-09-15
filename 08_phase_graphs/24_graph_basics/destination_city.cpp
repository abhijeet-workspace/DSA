// Destination City — https://leetcode.com/problems/destination-city/
// Paths form a line of cities; return the destination with outdegree 0.
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

std::string destCity(const std::vector<std::vector<std::string>>& paths) {
    std::unordered_set<std::string> outs;
    for (const auto& p : paths) outs.insert(p[0]);
    for (const auto& p : paths) {
        if (!outs.count(p[1])) return p[1];
    }
    return "";
}

int main() {
    std::cout << destCity({{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}})
              << " (expected Sao Paulo)\n";
    return 0;
}
