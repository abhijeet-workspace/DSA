// Coordinate compression — map values to dense ranks 1..U
// Sort unique values; lower_bound gives 1-based rank for Fenwick/SegTree indices.
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> compressRanks(const std::vector<int>& a) {
    std::vector<int> vals = a;
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());

    std::vector<int> ranks(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        ranks[i] = static_cast<int>(std::lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin()) + 1;
    }
    return ranks;
}

int main() {
    const std::vector<int> a = {40, 10, 40, 1000, -5};
    const std::vector<int> ranks = compressRanks(a);
    const std::vector<int> expected = {3, 2, 3, 4, 1};
    const bool ok = (ranks == expected);

    std::cout << "values:";
    for (int x : a) {
        std::cout << " " << x;
    }
    std::cout << "\nranks: ";
    for (int r : ranks) {
        std::cout << " " << r;
    }
    std::cout << "\nexpected: 3 2 3 4 1\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
