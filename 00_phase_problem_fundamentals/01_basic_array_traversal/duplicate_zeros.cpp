// Duplicate Zeros — LC 1089
// In-place: when seeing 0, shift right to make room for a duplicated 0.
#include <iostream>
#include <vector>

void duplicateZeros(std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    int zeros = 0;
    for (int x : arr)
        if (x == 0)
            ++zeros;

    // i walks original logical positions; j is the write index in the expanded view.
    for (int i = n - 1, j = n + zeros - 1; i >= 0; --i, --j) {
        if (j < n)
            arr[static_cast<size_t>(j)] = arr[static_cast<size_t>(i)];
        if (arr[static_cast<size_t>(i)] == 0) {
            --j;
            if (j < n)
                arr[static_cast<size_t>(j)] = 0;
        }
    }
}

int main() {
    std::vector<int> a{1, 0, 2, 3, 0, 4, 5, 0};
    duplicateZeros(a);
    for (int x : a)
        std::cout << x << " ";
    std::cout << "(expected 1 0 0 2 3 0 0 4)\n";
    return 0;
}
