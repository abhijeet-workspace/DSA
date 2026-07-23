// Difference Array — range-add technique (used in booking / car pooling)
// Many [l,r]+=val updates, then materialize the final array once.
#include <iostream>
#include <vector>

class DifferenceArray {
    std::vector<int> diff; // diff[i] = arr[i]-arr[i-1]; prefix(diff) rebuilds arr
    int n;
public:
    explicit DifferenceArray(const std::vector<int>& arr)
        : diff(arr.size() + 1, 0), n(static_cast<int>(arr.size())) {
        if (n == 0) {
            return;
        }
        diff[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            diff[i] = arr[i] - arr[i - 1]; // encode adjacent deltas
        }
    }

    void update(int l, int r, int val) {
        diff[l] += val; // start of range add
        if (r + 1 < static_cast<int>(diff.size())) {
            diff[r + 1] -= val; // cancel after r
        }
    }

    std::vector<int> getArray() const {
        std::vector<int> result(n);
        if (n == 0) {
            return result;
        }
        result[0] = diff[0];
        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] + diff[i]; // prefix of deltas
        }
        return result;
    }
};

int main() {
    DifferenceArray da({0, 0, 0, 0, 0});
    da.update(1, 3, 2);
    da.update(2, 4, 3);
    std::vector<int> result = da.getArray();
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << (i + 1 < result.size() ? " " : "");
    }
    std::cout << " (expected 0 2 5 5 3)\n";
    return 0;
}
