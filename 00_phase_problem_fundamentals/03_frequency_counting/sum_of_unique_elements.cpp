// Sum of Unique Elements — LC 1748
#include <iostream>
#include <vector>

int sumOfUnique(const std::vector<int>& nums) {
    int freq[101] = {};
    for (int x : nums)
        ++freq[x];
    int sum = 0;
    for (int v = 1; v <= 100; ++v)
        if (freq[v] == 1)
            sum += v;
    return sum;
}

int main() {
    std::cout << sumOfUnique({1, 2, 3, 2}) << " (expected 4)\n";
    std::cout << sumOfUnique({1, 1, 1, 1, 1}) << " (expected 0)\n";
    return 0;
}
