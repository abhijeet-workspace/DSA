// Jump Search — local teaching demo
// Jump √N steps on a sorted array, then linear-scan the block.
#include <cmath>
#include <iostream>
#include <vector>

int jumpSearch(const std::vector<int>& arr, int target) {
    const int n = static_cast<int>(arr.size());
    if (n == 0)
        return -1;

    int step = static_cast<int>(std::sqrt(n));
    int prev = 0;

    while (prev < n && arr[std::min(step, n) - 1] < target) {
        prev = step;
        step += static_cast<int>(std::sqrt(n));
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < std::min(step, n); ++i) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    std::cout << "=== Algorithm: Jump Search ===\n";
    std::vector<int> arr = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int target = 55;
    int index = jumpSearch(arr, target);
    std::cout << "Searching for " << target << " -> Index: " << index << '\n';
    return 0;
}
