// Two Sum — brute vs sorted two-pointer (reference)
// Unsorted: O(N^2) pairs. Sorted: opposite pointers O(N) after sort.
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> twoSumBrute(const std::vector<int>& a, int target) {
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[static_cast<size_t>(i)] + a[static_cast<size_t>(j)] == target)
                return {i, j};
        }
    }
    return {};
}

// Requires ascending sorted input; returns indices in that sorted view.
std::vector<int> twoSumSorted(const std::vector<int>& a, int target) {
    int L = 0, R = static_cast<int>(a.size()) - 1;
    while (L < R) {
        int sum = a[static_cast<size_t>(L)] + a[static_cast<size_t>(R)];
        if (sum == target) return {L, R};
        if (sum < target) ++L;
        else --R;
    }
    return {};
}

int main() {
    std::vector<int> list = {1, 5, 4, 6, 7, 2, 3};
    int target = 6;
    auto brute = twoSumBrute(list, target);
    std::cout << "brute [" << brute[0] << "," << brute[1] << "]\n";

    std::vector<int> sorted = list;
    std::sort(sorted.begin(), sorted.end());
    auto tp = twoSumSorted(sorted, target);
    if (tp.empty()) std::cout << "No Answer Found\n";
    else std::cout << "two-ptr on sorted [" << tp[0] << "," << tp[1] << "]\n";
    return 0;
}
