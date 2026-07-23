// Asymptotic Analysis — complexity class demos
// Show O(1), O(log n), O(n), O(n log n), O(n²), O(2^n) with a small timing check.
#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

int getFirst(const std::vector<int>& arr) {
    return arr[0]; // O(1) access
}

int binarySearch(const std::vector<int>& arr, int target) {
    int lo = 0;
    int hi = static_cast<int>(arr.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // avoid overflow
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int linearSum(const std::vector<int>& arr) {
    int total = 0;
    for (int x : arr) {
        total += x; // one pass
    }
    return total;
}

void mergeSort(std::vector<int>& arr, int lo, int hi) {
    if (lo >= hi) {
        return; // base case
    }
    int mid = lo + (hi - lo) / 2;
    mergeSort(arr, lo, mid); // left half
    mergeSort(arr, mid + 1, hi); // right half
    std::vector<int> temp;
    int l = lo;
    int r = mid + 1;
    while (l <= mid && r <= hi) {
        if (arr[l] <= arr[r]) {
            temp.push_back(arr[l++]);
        } else {
            temp.push_back(arr[r++]);
        }
    }
    while (l <= mid) {
        temp.push_back(arr[l++]);
    }
    while (r <= hi) {
        temp.push_back(arr[r++]);
    }
    for (int i = lo; i <= hi; ++i) {
        arr[i] = temp[i - lo]; // write merged
    }
}

bool hasDuplicateBrute(const std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { // O(n²) pairs
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

void generateSubsets(const std::vector<int>& arr, int idx, std::vector<int>& current,
                     std::vector<std::vector<int>>& result) {
    if (idx == static_cast<int>(arr.size())) {
        result.push_back(current); // one full subset
        return;
    }
    generateSubsets(arr, idx + 1, current, result); // exclude
    current.push_back(arr[idx]);
    generateSubsets(arr, idx + 1, current, result); // include
    current.pop_back(); // backtrack
}

void reverseInPlace(std::vector<int>& arr) {
    int lo = 0;
    int hi = static_cast<int>(arr.size()) - 1;
    while (lo < hi) {
        std::swap(arr[lo++], arr[hi--]); // O(1) extra space
    }
}

void benchmarkLinearVsQuadratic() {
    std::cout << "\nEmpirical Timing: Linear vs Quadratic\n";
    std::cout << std::string(50, '-') << "\n";
    std::vector<int> sizes = {1000, 5000, 10000, 50000};
    for (int n : sizes) {
        std::vector<int> data(n);
        for (int i = 0; i < n; ++i) {
            data[i] = i;
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        volatile long long s = linearSum(data);
        (void)s;
        auto t2 = std::chrono::high_resolution_clock::now();
        long long linearUs =
            std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

        auto t3 = std::chrono::high_resolution_clock::now();
        bool dup = hasDuplicateBrute(data);
        (void)dup;
        auto t4 = std::chrono::high_resolution_clock::now();
        long long quadUs =
            std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

        long long ratio = quadUs > 0 ? quadUs / std::max(1LL, linearUs) : 0;
        std::cout << "N=" << n << " | O(N): " << linearUs << "us"
                  << " | O(N^2): " << quadUs << "us"
                  << " | Ratio: " << ratio << "x\n";
    }
}

int main() {
    std::cout << "=== Asymptotic Analysis Demo ===\n\n";
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::cout << "O(1) getFirst: " << getFirst(arr) << "\n";

    std::vector<int> sorted_arr = arr;
    std::sort(sorted_arr.begin(), sorted_arr.end());
    std::cout << "O(log N) binarySearch(5): idx=" << binarySearch(sorted_arr, 5)
              << "\n";

    std::cout << "O(N) linearSum: " << linearSum(arr) << "\n";

    std::vector<int> to_sort = arr;
    mergeSort(to_sort, 0, static_cast<int>(to_sort.size()) - 1);
    std::cout << "O(N log N) mergeSort: [";
    for (int i = 0; i < static_cast<int>(to_sort.size()); ++i) {
        std::cout << to_sort[i]
                  << (i + 1 < static_cast<int>(to_sort.size()) ? "," : "");
    }
    std::cout << "]\n";

    std::cout << "O(N^2) hasDuplicateBrute: "
              << (hasDuplicateBrute(arr) ? "true" : "false") << "\n";

    std::vector<int> small = {1, 2, 3};
    std::vector<int> cur;
    std::vector<std::vector<int>> subsets;
    generateSubsets(small, 0, cur, subsets);
    std::cout << "O(2^N) subsets of {1,2,3}: count=" << subsets.size()
              << " (expected 8)\n";

    reverseInPlace(arr);
    std::cout << "O(1) space reverseInPlace: arr[0]=" << arr[0] << "\n";

    benchmarkLinearVsQuadratic();
    return 0;
}
