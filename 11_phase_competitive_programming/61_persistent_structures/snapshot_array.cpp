// Snapshot Array — LC 1146
#include <algorithm>
#include <iostream>
#include <vector>

struct SnapshotArray {
    int snap_id = 0;
    std::vector<std::vector<std::pair<int, int>>> hist;
    explicit SnapshotArray(int length) : hist(length) {
        for (int i = 0; i < length; ++i)
            hist[i].push_back({0, 0});
    }
    void set(int index, int val) {
        auto& h = hist[index];
        if (h.back().first == snap_id)
            h.back().second = val;
        else
            h.push_back({snap_id, val});
    }
    int snap() { return snap_id++; }
    int get(int index, int snap_id_) {
        auto& h = hist[index];
        auto it = std::upper_bound(h.begin(), h.end(), std::make_pair(snap_id_, int(1e9)));
        --it;
        return it->second;
    }
};

int main() {
    SnapshotArray sa(3);
    sa.set(0, 5);
    int id = sa.snap();
    sa.set(0, 6);
    std::cout << "snap=" << id << " get=" << sa.get(0, 0) << " (expected 5)\n";
    return 0;
}
