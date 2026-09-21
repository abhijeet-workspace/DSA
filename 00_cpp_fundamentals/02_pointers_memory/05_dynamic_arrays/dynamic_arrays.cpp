// Dynamic Arrays — C++ fundamentals
// Allocate with new[], write/read, and free with delete[] (not delete).
#include <iostream>

int main() {
    int n = 5;
    int* arr = new int[n]; // contiguous heap array; uninitialized here

    for (int i = 0; i < n; ++i) {
        arr[i] = (i + 1) * 10;
    }

    std::cout << "heap array:";
    for (int i = 0; i < n; ++i) {
        std::cout << ' ' << arr[i];
    }
    std::cout << '\n';

    delete[] arr; // must match new[]
    arr = nullptr;

    // Prefer in real code:
    // std::vector<int> v(n);
    // or std::unique_ptr<int[]> p(new int[n]);

    int* scalar = new int(42);
    std::cout << "scalar heap int=" << *scalar << '\n';
    delete scalar; // plain delete for non-array new
    scalar = nullptr;

    return 0;
}
