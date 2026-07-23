// Merge Triplets — https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
// Keep triplets that never exceed target; max each coordinate independently.
#include <iostream>
#include <vector>
#include <algorithm>

bool mergeTriplets(const std::vector<std::vector<int>>& triplets,
                   const std::vector<int>& target) {
    int a = 0, b = 0, c = 0;
    for (const auto& t : triplets) {
        if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
        a = std::max(a, t[0]);
        b = std::max(b, t[1]);
        c = std::max(c, t[2]);
    }
    return a == target[0] && b == target[1] && c == target[2];
}

int main() {
    const std::vector<std::vector<int>> t = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};
    const std::vector<int> g = {2, 7, 5};
    std::cout << std::boolalpha << mergeTriplets(t, g) << " (expected true)\n";
    return 0;
}
