// Replace Words — https://leetcode.com/problems/replace-words/
// Trie of dictionary roots; replace each word by shortest root prefix.
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct TrieNode {
    TrieNode* children[26]{};
    bool isEnd = false;
};

class Trie {
    TrieNode* root = new TrieNode();

    void clear(TrieNode* node) {
        if (!node)
            return;
        for (TrieNode* ch : node->children)
            clear(ch);
        delete node;
    }

  public:
    ~Trie() { clear(root); }

    void insert(const std::string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            const int i = c - 'a';
            if (!cur->children[i])
                cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    // shortest root that is a prefix of word; empty if none
    std::string shortestRoot(const std::string& word) const {
        TrieNode* cur = root;
        std::string path;
        for (char c : word) {
            const int i = c - 'a';
            if (!cur->children[i])
                return {};
            cur = cur->children[i];
            path.push_back(c);
            if (cur->isEnd)
                return path; // first end = shortest
        }
        return {};
    }
};

std::string replaceWords(const std::vector<std::string>& dictionary, const std::string& sentence) {
    Trie trie;
    for (const auto& root : dictionary)
        trie.insert(root);
    std::istringstream in(sentence);
    std::ostringstream out;
    std::string word;
    bool first = true;
    while (in >> word) {
        if (!first)
            out << ' ';
        first = false;
        const std::string root = trie.shortestRoot(word);
        out << (root.empty() ? word : root);
    }
    return out.str();
}

int main() {
    std::cout << replaceWords({"cat", "bat", "rat"}, "the cattle was rattled by the battery")
              << " (expected the cat was rat by the bat)\n"
              << replaceWords({"a", "b", "c"}, "aadsfasf absbs bbab cadsfafs")
              << " (expected a a b c)\n";
    return 0;
}
