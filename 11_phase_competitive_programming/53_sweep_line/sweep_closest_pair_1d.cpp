// Sweep line 1D — union length of intervals
// +1 at starts, -1 at ends; accumulate length while active > 0.
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

long long unionLength(const std::vector<std::pair<int, int>>& intervals) {
    std::vector<std::pair<int, int>> events;
    events.reserve(intervals.size() * 2);
    for (const auto& iv : intervals) {
        if (iv.first >= iv.second) {
            continue;
        }
        events.push_back({iv.first, +1});
        events.push_back({iv.second, -1});
    }
    std::sort(events.begin(), events.end(), [](const auto& A, const auto& B) {
        if (A.first != B.first) {
            return A.first < B.first;
        }
        return A.second < B.second; // ends before starts at same x
    });

    long long total = 0;
    int active = 0;
    int prevX = 0;
    bool havePrev = false;
    for (const auto& e : events) {
        if (havePrev && active > 0) {
            total += static_cast<long long>(e.first) - prevX;
        }
        active += e.second;
        prevX = e.first;
        havePrev = true;
    }
    return total;
}

int main() {
    const long long ua = unionLength({{1, 5}, {2, 3}, {6, 8}});
    const long long ub = unionLength({{1, 4}, {4, 6}});
    const long long uc = unionLength({{1, 10}, {2, 3}, {4, 8}});

    // touching [1,4] U [4,6]: end-before-start → length 5
    const bool ok = (ua == 6 && ub == 5 && uc == 9);
    std::cout << "union A=" << ua << " (expected 6)\n";
    std::cout << "union B (touching)=" << ub << " (expected 5)\n";
    std::cout << "union C=" << uc << " (expected 9)\n";
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
