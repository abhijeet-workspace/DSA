// Count Inversions — merge-sort variant counting cross-half pairs
// Count pairs (i,j) with i < j and arr[i] > arr[j] in O(N log N).
#include <iostream>
#include <vector>

long long mergeCount(std::vector<int>& arr, std::vector<int>& temp, int left, int mid,
                     int right) {
    int i = left, j = mid, k = left;
    long long inv = 0;
    while (i <= mid - 1 && j <= right) {
        if (arr[static_cast<size_t>(i)] <= arr[static_cast<size_t>(j)]) {
            temp[static_cast<size_t>(k++)] = arr[static_cast<size_t>(i++)];
        } else {
            temp[static_cast<size_t>(k++)] = arr[static_cast<size_t>(j++)];
            inv += (mid - i); // all left[i..mid) invert with this right item
        }
    }
    while (i <= mid - 1) {
        temp[static_cast<size_t>(k++)] = arr[static_cast<size_t>(i++)];
    }
    while (j <= right) {
        temp[static_cast<size_t>(k++)] = arr[static_cast<size_t>(j++)];
    }
    for (int t = left; t <= right; ++t) {
        arr[static_cast<size_t>(t)] = temp[static_cast<size_t>(t)];
    }
    return inv;
}

long long mergeSortCount(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    long long inv = 0;
    if (left < right) {
        const int mid = left + (right - left) / 2;
        inv += mergeSortCount(arr, temp, left, mid);
        inv += mergeSortCount(arr, temp, mid + 1, right);
        inv += mergeCount(arr, temp, left, mid + 1, right);
    }
    return inv;
}

long long countInversions(std::vector<int>& arr) {
    std::vector<int> temp(arr.size());
    return mergeSortCount(arr, temp, 0, static_cast<int>(arr.size()) - 1);
}

int main() {
    std::vector<int> arr = {2, 4, 1, 3, 5};
    std::cout << countInversions(arr) << " (expected 3)\n";
    return 0;
}
