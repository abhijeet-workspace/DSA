// Snapshot Array — https://leetcode.com/problems/snapshot-array/
// set/snap/get; get binary-searches the latest value with snap_id <= query.
#include <iostream>
#include <vector>
#include <utility>

class SnapshotArray {
    std::vector<std::vector<std::pair<int, int>>> hist; // per index: (snap_id, value)
    int snap_id = 0;

public:
    explicit SnapshotArray(int length) : hist(static_cast<size_t>(length)) {
        for (auto& h : hist) {
            h.push_back({0, 0});
        }
    }

    void set(int index, int val) {
        auto& h = hist[static_cast<size_t>(index)];
        if (h.back().first == snap_id) {
            h.back().second = val;
        } else {
            h.push_back({snap_id, val});
        }
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id_q) {
        const auto& h = hist[static_cast<size_t>(index)];
        int lo = 0;
        int hi = static_cast<int>(h.size()) - 1;
        int ans = 0;
        while (lo <= hi) {
            const int mid = lo + (hi - lo) / 2;
            if (h[static_cast<size_t>(mid)].first <= snap_id_q) {
                ans = h[static_cast<size_t>(mid)].second;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    SnapshotArray sa(3);
    sa.set(0, 5);
    std::cout << sa.snap() << " (expected 0)\n";
    sa.set(0, 6);
    std::cout << sa.get(0, 0) << " (expected 5)\n";
    return 0;
}
