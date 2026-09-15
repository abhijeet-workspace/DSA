// Range Module — https://leetcode.com/problems/range-module/
// Track disjoint covered intervals in a map; add/remove/query.
#include <iostream>
#include <map>
#include <vector>

class RangeModule {
    std::map<int, int> intervals; // start -> end

public:
    void addRange(int left, int right) {
        auto it = intervals.lower_bound(left);
        if (it != intervals.begin()) {
            auto prev = std::prev(it);
            if (prev->second >= left) it = prev;
        }
        while (it != intervals.end() && it->first <= right) {
            left = std::min(left, it->first);
            right = std::max(right, it->second);
            it = intervals.erase(it);
        }
        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) return false;
        --it;
        return it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = intervals.lower_bound(left);
        if (it != intervals.begin()) {
            auto prev = std::prev(it);
            if (prev->second > left) {
                int pe = prev->second;
                prev->second = left;
                if (pe > right) intervals[right] = pe;
            }
        }
        it = intervals.lower_bound(left);
        while (it != intervals.end() && it->first < right) {
            if (it->second <= right) {
                it = intervals.erase(it);
            } else {
                int e = it->second;
                intervals.erase(it);
                intervals[right] = e;
                break;
            }
        }
    }
};

int main() {
    RangeModule rm;
    rm.addRange(10, 20);
    rm.removeRange(14, 16);
    std::cout << std::boolalpha
              << rm.queryRange(10, 14) << " (expected true)\n"
              << rm.queryRange(13, 15) << " (expected false)\n"
              << rm.queryRange(16, 17) << " (expected true)\n";
    return 0;
}
