// Search in a Sorted Array of Unknown Size — https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
// ArrayReader.get(i) is 2^31-1 out of range. Exponential search then binary search.
#include <iostream>
#include <limits>
#include <vector>

class ArrayReader {
    std::vector<int> data;

public:
    explicit ArrayReader(std::vector<int> d) : data(std::move(d)) {}

    int get(int index) const {
        if (index < 0 || index >= static_cast<int>(data.size())) {
            return std::numeric_limits<int>::max();
        }
        return data[static_cast<size_t>(index)];
    }
};

int search(const ArrayReader& reader, int target) {
    int hi = 1;
    while (reader.get(hi) < target) {
        hi <<= 1; // grow until we pass the target
    }
    int lo = hi >> 1;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        const int v = reader.get(mid);
        if (v == target) {
            return mid;
        }
        if (v > target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}

int main() {
    const ArrayReader reader({-1, 0, 3, 5, 9, 12});
    std::cout << search(reader, 9) << " (expected 4)\n"
              << search(reader, 2) << " (expected -1)\n";
    return 0;
}
