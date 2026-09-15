// Map Sum Pairs — https://leetcode.com/problems/map-sum-pairs/
// Trie stores prefix sums; insert updates delta along the path.
#include <iostream>
#include <string>
#include <unordered_map>

struct TrieNode {
    TrieNode* children[26]{};
    int prefixSum = 0; // sum of values of keys under this node
};

class MapSum {
    TrieNode* root = new TrieNode();
    std::unordered_map<std::string, int> val; // last value per key

    void clear(TrieNode* node) {
        if (!node)
            return;
        for (TrieNode* ch : node->children)
            clear(ch);
        delete node;
    }

  public:
    ~MapSum() { clear(root); }

    void insert(const std::string& key, int value) {
        const int delta = value - (val.count(key) ? val[key] : 0);
        val[key] = value;
        TrieNode* cur = root;
        for (char c : key) {
            const int i = c - 'a';
            if (!cur->children[i])
                cur->children[i] = new TrieNode();
            cur = cur->children[i];
            cur->prefixSum += delta; // update every prefix node
        }
    }

    int sum(const std::string& prefix) const {
        TrieNode* cur = root;
        for (char c : prefix) {
            const int i = c - 'a';
            if (!cur->children[i])
                return 0;
            cur = cur->children[i];
        }
        return cur->prefixSum;
    }
};

int main() {
    MapSum ms;
    ms.insert("apple", 3);
    std::cout << ms.sum("ap") << " (expected 3)\n";
    ms.insert("app", 2);
    std::cout << ms.sum("ap") << " (expected 5)\n";
    ms.insert("apple", 2); // overwrite
    std::cout << ms.sum("ap") << " (expected 4)\n";
    return 0;
}
