// Sweep line — skyline critical height-change points (LC 218 style)
// Multiset of active heights; emit (x, h) when max changes.
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Building {
    int l;
    int r;
    int h;
};

std::vector<std::pair<int, int>> getSkyline(const std::vector<Building>& buildings) {
    std::vector<std::pair<int, int>> events;
    for (const Building& b : buildings) {
        events.push_back({b.l, -b.h}); // start encoded negative
        events.push_back({b.r, b.h});  // end
    }
    // Same x: starts before ends; taller start first; shorter end first.
    std::sort(events.begin(), events.end(), [](const auto& A, const auto& B) {
        if (A.first != B.first) {
            return A.first < B.first;
        }
        return A.second < B.second;
    });

    std::multiset<int> active;
    active.insert(0);
    int prev = 0;
    std::vector<std::pair<int, int>> out;

    for (const auto& e : events) {
        if (e.second < 0) {
            active.insert(-e.second);
        } else {
            active.erase(active.find(e.second));
        }
        const int cur = *active.rbegin();
        if (cur != prev) {
            out.push_back({e.first, cur});
            prev = cur;
        }
    }
    return out;
}

int main() {
    const std::vector<Building> buildings = {
        {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8},
    };
    const auto sky = getSkyline(buildings);
    const std::vector<std::pair<int, int>> expected = {
        {2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0},
    };

    const bool ok = (sky == expected);
    std::cout << "skyline points:\n";
    for (const auto& p : sky) {
        std::cout << "  (" << p.first << "," << p.second << ")\n";
    }
    std::cout << (ok ? "OK (matches expected)\n" : "FAIL\n");
    return ok ? 0 : 1;
}
