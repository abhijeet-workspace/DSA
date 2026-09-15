// Couples Holding Hands — https://leetcode.com/problems/couples-holding-hands/
// Partner of x is x^1. For each couple seat (2i,2i+1), swap partner into place.
#include <iostream>
#include <vector>
#include <utility>

int minSwapsCouples(std::vector<int>& row) {
    const int n = static_cast<int>(row.size());
    std::vector<int> pos(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        pos[static_cast<size_t>(row[static_cast<size_t>(i)])] = i;
    }
    int swaps = 0;
    for (int i = 0; i < n; i += 2) {
        const int partner = row[static_cast<size_t>(i)] ^ 1;
        if (row[static_cast<size_t>(i + 1)] == partner) continue;
        const int j = pos[static_cast<size_t>(partner)];
        const int other = row[static_cast<size_t>(i + 1)];
        std::swap(row[static_cast<size_t>(i + 1)], row[static_cast<size_t>(j)]);
        pos[static_cast<size_t>(other)] = j;
        pos[static_cast<size_t>(partner)] = i + 1;
        ++swaps;
    }
    return swaps;
}

int main() {
    std::vector<int> a = {0, 2, 1, 3};
    std::vector<int> b = {3, 2, 0, 1};
    std::cout << minSwapsCouples(a) << " (expected 1)\n"
              << minSwapsCouples(b) << " (expected 0)\n";
    return 0;
}
