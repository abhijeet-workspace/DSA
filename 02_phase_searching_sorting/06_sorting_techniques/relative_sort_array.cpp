// Relative Sort Array — LC 1122
// Sort arr1 by relative order of arr2, then remaining ascending.
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::unordered_map<int, int> rank;
    for (int i = 0; i < static_cast<int>(arr2.size()); ++i) {
        rank[arr2[static_cast<size_t>(i)]] = i;
    }
    const int unbound = static_cast<int>(arr2.size());
    std::sort(arr1.begin(), arr1.end(), [&](int a, int b) {
        const int ra = rank.count(a) ? rank[a] : unbound + a;
        const int rb = rank.count(b) ? rank[b] : unbound + b;
        return ra < rb;
    });
    return arr1;
}

int main() {
    std::vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    std::vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    const auto out = relativeSortArray(arr1, arr2);
    for (size_t i = 0; i < out.size(); ++i) {
        std::cout << out[i] << (i + 1 < out.size() ? " " : "");
    }
    std::cout << " (expected 2 2 2 1 4 3 3 9 6 7 19)\n";
    return 0;
}
