// Recurrence Relations — merge sort, binary search, inversion count
// Map classic recurrences T(n)=2T(n/2)+O(n) and T(n)=T(n/2)+O(1) to code.
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) {
        return; // T(1)
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m); // T(n/2)
    mergeSort(arr, m + 1, r); // T(n/2)
    merge(arr, l, m, r); // O(n) combine
}

int binarySearch(const std::vector<int>& arr, int l, int r, int target) {
    if (l > r) {
        return -1; // not found
    }
    int m = l + (r - l) / 2;
    if (arr[m] == target) {
        return m;
    }
    if (arr[m] > target) {
        return binarySearch(arr, l, m - 1, target); // T(n/2)
    }
    return binarySearch(arr, m + 1, r, target);
}

long long mergeAndCount(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[m + 1 + j];
    }
    long long count = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            count += (n1 - i); // remaining L > R[j]
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
    return count;
}

long long countInversions(std::vector<int>& arr, int l, int r) {
    if (l >= r) {
        return 0;
    }
    int m = l + (r - l) / 2;
    long long count = 0;
    count += countInversions(arr, l, m);
    count += countInversions(arr, m + 1, r);
    count += mergeAndCount(arr, l, m, r);
    return count;
}

int main() {
    std::cout << "=== Recurrence Relations Demo ===\n\n";

    std::vector<int> arr1 = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "Original: ";
    for (int x : arr1) {
        std::cout << x << " ";
    }
    std::cout << "\nMerge Sort (T(n)=2T(n/2)+O(n))...\n";
    mergeSort(arr1, 0, static_cast<int>(arr1.size()) - 1);
    std::cout << "Sorted: ";
    for (int x : arr1) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    int target = 43;
    std::cout << "Binary Search for " << target << " (T(n)=T(n/2)+O(1))...\n";
    int idx = binarySearch(arr1, 0, static_cast<int>(arr1.size()) - 1, target);
    if (idx != -1) {
        std::cout << "Found at index: " << idx << "\n\n";
    } else {
        std::cout << "Not found.\n\n";
    }

    std::vector<int> arr2 = {8, 4, 2, 1};
    std::cout << "Inversion array: ";
    for (int x : arr2) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    long long invs = countInversions(arr2, 0, static_cast<int>(arr2.size()) - 1);
    std::cout << "Inversions: " << invs << " (expected 6)\n";
    return 0;
}
