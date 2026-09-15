// Bus Routes — https://leetcode.com/problems/bus-routes/
// Min buses to go from source to target; each route is a cycle of stops. BFS on buses.
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int numBusesToDestination(const std::vector<std::vector<int>>& routes, int source, int target) {
    if (source == target) {
        return 0;
    }
    std::unordered_map<int, std::vector<int>> stopToBuses;
    for (int b = 0; b < static_cast<int>(routes.size()); ++b) {
        for (int stop : routes[static_cast<size_t>(b)]) {
            stopToBuses[stop].push_back(b);
        }
    }
    std::queue<int> q; // stops
    std::unordered_set<int> seenStop;
    std::unordered_set<int> seenBus;
    q.push(source);
    seenStop.insert(source);
    int buses = 0;
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        ++buses;
        for (int i = 0; i < sz; ++i) {
            const int stop = q.front();
            q.pop();
            for (int b : stopToBuses[stop]) {
                if (seenBus.count(b)) {
                    continue;
                }
                seenBus.insert(b);
                for (int nxt : routes[static_cast<size_t>(b)]) {
                    if (nxt == target) {
                        return buses;
                    }
                    if (!seenStop.count(nxt)) {
                        seenStop.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    std::cout << numBusesToDestination({{1, 2, 7}, {3, 6, 7}}, 1, 6) << " (expected 2)\n";
    std::cout << numBusesToDestination({{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}}, 15, 12)
              << " (expected -1)\n";
    return 0;
}
