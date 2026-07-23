// Implement Trie — https://leetcode.com/problems/implement-trie-prefix-tree/
// Insert / search / startsWith on lowercase words via 26-way prefix tree.
#include <iostream>
#include <string>

struct TrieNode {
    TrieNode* children[26]{};
    bool isEnd = false;
};

class Trie {
    TrieNode* root = new TrieNode();

    void clear(TrieNode* node) {
        if (!node) return;
        for (TrieNode* ch : node->children) clear(ch);
        delete node;
    }

public:
    ~Trie() { clear(root); }

    void insert(const std::string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            const int i = c - 'a';
            if (!cur->children[i]) cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->isEnd = true; // mark complete word
    }

    bool search(const std::string& word) const {
        TrieNode* cur = root;
        for (char c : word) {
            const int i = c - 'a';
            if (!cur->children[i]) return false;
            cur = cur->children[i];
        }
        return cur->isEnd; // prefix alone is not enough
    }

    bool startsWith(const std::string& prefix) const {
        TrieNode* cur = root;
        for (char c : prefix) {
            const int i = c - 'a';
            if (!cur->children[i]) return false;
            cur = cur->children[i];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    std::cout << std::boolalpha
              << trie.search("apple") << " (expected true)\n"
              << trie.search("app") << " (expected false)\n"
              << trie.startsWith("app") << " (expected true)\n";
    trie.insert("app");
    std::cout << trie.search("app") << " (expected true)\n";
    return 0;
}
