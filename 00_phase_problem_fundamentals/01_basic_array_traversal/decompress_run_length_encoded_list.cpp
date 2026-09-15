// Decompress Run-Length Encoded List — LC 1313
// Pairs (freq, val) expand to freq copies of val.
#include <iostream>
#include <vector>

std::vector<int> decompressRLElist(const std::vector<int>& nums) {
    std::vector<int> ans;
    for (size_t i = 0; i + 1 < nums.size(); i += 2) {
        const int freq = nums[i];
        const int val = nums[i + 1];
        for (int k = 0; k < freq; ++k) ans.push_back(val);
    }
    return ans;
}

int main() {
    for (int x : decompressRLElist({1, 2, 3, 4})) std::cout << x << " ";
    std::cout << "(expected 2 4 4 4)\n";
    return 0;
}
