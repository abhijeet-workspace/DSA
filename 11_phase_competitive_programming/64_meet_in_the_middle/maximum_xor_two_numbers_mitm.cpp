// Maximum XOR of Two Numbers — LC 421 (trie; MITM not preferred)
#include <iostream>
#include <vector>

struct Trie {
    Trie* next[2]{};
};

void insert(Trie* root, int x) {
    Trie* cur = root;
    for (int b = 31; b >= 0; --b) {
        int bit = (x >> b) & 1;
        if (!cur->next[bit])
            cur->next[bit] = new Trie();
        cur = cur->next[bit];
    }
}

int bestXor(Trie* root, int x) {
    Trie* cur = root;
    int ans = 0;
    for (int b = 31; b >= 0; --b) {
        int bit = (x >> b) & 1;
        if (cur->next[bit ^ 1]) {
            ans |= 1 << b;
            cur = cur->next[bit ^ 1];
        } else
            cur = cur->next[bit];
    }
    return ans;
}

int findMaximumXOR(const std::vector<int>& nums) {
    Trie* root = new Trie();
    int best = 0;
    for (int x : nums) {
        insert(root, x);
        best = std::max(best, bestXor(root, x));
    }
    return best;
}

int main() {
    std::cout << findMaximumXOR({3, 10, 5, 25, 2, 8}) << " (expected 28)\n";
    return 0;
}
