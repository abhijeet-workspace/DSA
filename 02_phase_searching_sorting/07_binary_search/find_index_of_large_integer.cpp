// Find the Index of the Large Integer —
// https://leetcode.com/problems/find-the-index-of-the-large-integer/ All elements equal except one
// larger; compareSub on halves to binary-search its index.
#include <iostream>
#include <vector>

class ArrayReader {
    std::vector<int> data;

  public:
    explicit ArrayReader(std::vector<int> d) : data(std::move(d)) {}

    int length() const { return static_cast<int>(data.size()); }

    int compareSub(int l, int r, int x, int y) const {
        long long left = 0;
        long long right = 0;
        for (int i = l; i <= r; ++i) {
            left += data[static_cast<size_t>(i)];
        }
        for (int i = x; i <= y; ++i) {
            right += data[static_cast<size_t>(i)];
        }
        if (left == right) {
            return 0;
        }
        return left > right ? 1 : -1;
    }
};

int getIndex(const ArrayReader& reader) {
    int lo = 0;
    int hi = reader.length() - 1;
    while (lo < hi) {
        const int len = hi - lo + 1;
        const int mid = lo + (len / 2) - 1; // end of left half when even
        if (len % 2 == 0) {
            const int cmp = reader.compareSub(lo, mid, mid + 1, hi);
            if (cmp >= 0) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        } else {
            const int cmp = reader.compareSub(lo, mid, mid + 2, hi);
            if (cmp == 0) {
                return mid + 1; // the skipped middle is the large one
            }
            if (cmp > 0) {
                hi = mid;
            } else {
                lo = mid + 2;
            }
        }
    }
    return lo;
}

int main() {
    std::cout << getIndex(ArrayReader({7, 7, 7, 7, 10, 7, 7, 7})) << " (expected 4)\n"
              << getIndex(ArrayReader({6, 6, 12})) << " (expected 2)\n";
    return 0;
}
