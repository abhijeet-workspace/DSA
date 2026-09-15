// Zigzag Iterator — https://leetcode.com/problems/zigzag-iterator/ (premium)
// Round-robin k vectors via queue of (vecIdx, elemIdx) — k-way style.
#include <iostream>
#include <queue>
#include <vector>

class ZigzagIterator {
    std::vector<std::vector<int>> data;
    std::queue<std::pair<int, int>> q; // vec, idx

public:
    ZigzagIterator(std::vector<int>& v1, std::vector<int>& v2) : data{v1, v2} {
        if (!v1.empty()) q.push({0, 0});
        if (!v2.empty()) q.push({1, 0});
    }

    int next() {
        auto [vi, ei] = q.front();
        q.pop();
        int val = data[static_cast<size_t>(vi)][static_cast<size_t>(ei)];
        if (ei + 1 < static_cast<int>(data[static_cast<size_t>(vi)].size())) {
            q.push({vi, ei + 1});
        }
        return val;
    }

    bool hasNext() const { return !q.empty(); }
};

int main() {
    std::vector<int> v1 = {1, 2};
    std::vector<int> v2 = {3, 4, 5, 6};
    ZigzagIterator z(v1, v2);
    while (z.hasNext()) std::cout << z.next() << " ";
    std::cout << "(expected 1 3 2 4 5 6)\n";
    return 0;
}
