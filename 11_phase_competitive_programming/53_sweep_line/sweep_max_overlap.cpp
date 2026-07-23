// Sweep line — maximum overlapping intervals
// +1 at start, -1 at end; ends before starts so touching does not count.
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int maxOverlap(const std::vector<std::pair<int, int>>& intervals) {
    std::vector<std::pair<int, int>> events;
    events.reserve(intervals.size() * 2);
    for (const auto& iv : intervals) {
        events.push_back({iv.first, +1});
        events.push_back({iv.second, -1});
    }
    std::sort(events.begin(), events.end(), [](const auto& A, const auto& B) {
        if (A.first != B.first) {
            return A.first < B.first;
        }
        return A.second < B.second; // ends (-1) before starts (+1)
    });

    int active = 0;
    int best = 0;
    for (const auto& e : events) {
        active += e.second;
        best = std::max(best, active);
    }
    return best;
}

int main() {
    const int ra = maxOverlap({{0, 30}, {5, 10}, {15, 20}});
    const int rb = maxOverlap({{7, 10}, {2, 4}});
    const int rc = maxOverlap({{1, 2}, {2, 3}, {3, 4}});

    const bool ok = (ra == 2 && rb == 1 && rc == 1);
    std::cout << "overlap A=" << ra << " (expected 2)\n";
    std::cout << "overlap B=" << rb << " (expected 1)\n";
    std::cout << "overlap C (touching)=" << rc << " (expected 1)\n";
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
