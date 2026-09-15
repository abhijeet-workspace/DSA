// Maximum XOR of Two Numbers —
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/ Binary trie (MSB→LSB);
// greedily take opposite bit when present.
#include <algorithm>
#include <iostream>
#include <vector>

struct BitNode {
    BitNode* ch[2]{};
};

int findMaximumXOR(const std::vector<int>& nums) {
    BitNode* root = new BitNode();
    auto insert = [&](int x) {
        BitNode* cur = root;
        for (int b = 31; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (!cur->ch[bit])
                cur->ch[bit] = new BitNode();
            cur = cur->ch[bit];
        }
    };
    auto query = [&](int x) {
        BitNode* cur = root;
        int val = 0;
        for (int b = 31; b >= 0; --b) {
            int bit = (x >> b) & 1;
            int want = bit ^ 1;
            if (cur->ch[want]) {
                val |= 1 << b;
                cur = cur->ch[want];
            } else {
                cur = cur->ch[bit];
            }
        }
        return val;
    };
    int ans = 0;
    insert(nums[0]);
    for (size_t i = 1; i < nums.size(); ++i) {
        ans = std::max(ans, query(nums[i]));
        insert(nums[i]);
    }
    return ans;
}

int main() {
    std::cout << findMaximumXOR({3, 10, 5, 25, 2, 8}) << " (expected 28)\n"
              << findMaximumXOR({0}) << " (expected 0)\n"
              << findMaximumXOR({2, 4}) << " (expected 6)\n";
    return 0;
}
