// Longest Word in Dictionary — https://leetcode.com/problems/longest-word-in-dictionary/
// Trie DFS only through end-marked prefixes; track longest / lex-smallest.
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Node {
    Node* ch[26]{};
    bool end = false;
};

std::string longestWord(const std::vector<std::string>& words) {
    Node* root = new Node();
    for (const auto& w : words) {
        Node* cur = root;
        for (char c : w) {
            int i = c - 'a';
            if (!cur->ch[i])
                cur->ch[i] = new Node();
            cur = cur->ch[i];
        }
        cur->end = true;
    }
    std::string best, path;
    std::function<void(Node*)> dfs = [&](Node* node) {
        if (path.size() > best.size() || (path.size() == best.size() && path < best))
            best = path;
        for (int i = 0; i < 26; ++i) {
            if (node->ch[i] && node->ch[i]->end) {
                path.push_back(static_cast<char>('a' + i));
                dfs(node->ch[i]);
                path.pop_back();
            }
        }
    };
    dfs(root);
    return best;
}

int main() {
    std::cout << longestWord({"w", "wo", "wor", "worl", "world"}) << " (expected world)\n"
              << longestWord({"a", "banana", "app", "appl", "ap", "apply", "apple"})
              << " (expected apple)\n";
    return 0;
}
