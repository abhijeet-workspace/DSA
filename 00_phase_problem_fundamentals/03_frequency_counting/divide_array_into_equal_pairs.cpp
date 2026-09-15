// Divide Array Into Equal Pairs — LC 2206
#include <iostream>
#include <vector>

bool divideArray(const std::vector<int>& nums) {
    int freq[501] = {};
    for (int x : nums) ++freq[x];
    for (int c : freq) if (c % 2) return false;
    return true;
}

int main() {
    std::cout << std::boolalpha
              << divideArray({3, 2, 3, 2, 2, 2}) << " (expected true)\n"
              << divideArray({1, 2, 3, 4}) << " (expected false)\n";
    return 0;
}
