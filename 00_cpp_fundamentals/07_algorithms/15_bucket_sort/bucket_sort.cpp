// Bucket sort — uniform floats in [0,1)
// Scatter into n buckets, sort each, gather.
#include <algorithm>
#include <iostream>
#include <vector>

void bucketSort(std::vector<float>& arr) {
    int n = static_cast<int>(arr.size());
    if (n <= 0) {
        return;
    }
    std::vector<std::vector<float>> buckets(n); // n empty buckets
    for (int i = 0; i < n; ++i) {
        int bi = static_cast<int>(n * arr[i]); // bucket index
        if (bi >= n) { // clamp if value==1.0 edge
            bi = n - 1;
        }
        buckets[bi].push_back(arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end()); // local sort
    }
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (float val : buckets[i]) {
            arr[index++] = val; // concatenate
        }
    }
}

int main() {
    std::cout << "=== Algorithm: Bucket Sort ===" << std::endl;
    std::vector<float> arr = {0.897f, 0.565f, 0.656f, 0.1234f, 0.665f, 0.3434f};
    bucketSort(arr);
    std::cout << "Sorted: ";
    for (float x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
