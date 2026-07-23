// Top K Frequent Elements — LC 347
// Count freqs, bucket-sort by frequency in [1..N], collect from high→low.
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int x : nums) ++freq[x];
    std::vector<std::vector<int>> buckets(nums.size() + 1);
    for (const auto& [val, f] : freq)
        buckets[static_cast<size_t>(f)].push_back(val);
    std::vector<int> ans;
    for (int f = static_cast<int>(buckets.size()) - 1;
         f >= 0 && static_cast<int>(ans.size()) < k; --f) {
        for (int v : buckets[static_cast<size_t>(f)]) {
            ans.push_back(v);
            if (static_cast<int>(ans.size()) == k) return ans;
        }
    }
    return ans;
}

int main() {
    auto ans = topKFrequent({1, 1, 1, 2, 2, 3}, 2);
    std::cout << "topK:";
    for (int x : ans) std::cout << " " << x;
    std::cout << " (expected 1 2)\n";
    return 0;
}
