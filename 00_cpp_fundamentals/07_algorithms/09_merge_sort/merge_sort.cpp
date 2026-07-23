// Merge Sort — local teaching demo
// Divide array in half, sort recursively, then merge sorted halves.
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2); // temp halves
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++]; // stable pick
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return; // one element
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    std::cout << "=== Algorithm: Merge Sort ===\n";
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    std::cout << "Unsorted: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';

    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);

    std::cout << "Sorted:   ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}
