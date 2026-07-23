// Interpolation Search — local teaching demo
// Estimate target position from value distribution (uniform sorted arrays).
#include <iostream>
#include <vector>

int interpolationSearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + static_cast<int>(
            (static_cast<double>(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if (arr[pos] == target) {
            return pos;
        }
        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    std::cout << "=== Algorithm: Interpolation Search ===\n";
    std::vector<int> arr = {10, 12, 13, 16, 18, 20, 22, 24, 27, 30};
    int target = 18;
    int index = interpolationSearch(arr, target);
    std::cout << "Searching for " << target << " -> Index: " << index << '\n';
    return 0;
}
