// Add and Search Words — https://leetcode.com/problems/design-add-and-search-words-data-structure/
// Trie storage; '.' matches any letter via DFS over children.
#include <iostream>
#include <string>

struct Node {
    Node* next[26]{};
    bool end = false;
};

class WordDictionary {
    Node* root = new Node();

    bool dfs(const std::string& w, int i, Node* node) const {
        if (!node) return false;
        if (i == static_cast<int>(w.size())) return node->end;
        if (w[static_cast<size_t>(i)] == '.') {
            for (int c = 0; c < 26; ++c) { // try every letter
                if (dfs(w, i + 1, node->next[c])) return true;
            }
            return false;
        }
        return dfs(w, i + 1, node->next[w[static_cast<size_t>(i)] - 'a']);
    }

public:
    void addWord(const std::string& word) {
        Node* cur = root;
        for (char c : word) {
            const int i = c - 'a';
            if (!cur->next[i]) cur->next[i] = new Node();
            cur = cur->next[i];
        }
        cur->end = true;
    }

    bool search(const std::string& word) const { return dfs(word, 0, root); }
};

int main() {
    WordDictionary d;
    d.addWord("bad");
    d.addWord("dad");
    std::cout << std::boolalpha
              << d.search("pad") << " (expected false)\n"
              << d.search(".ad") << " (expected true)\n"
              << d.search("b..") << " (expected true)\n";
    return 0;
}
