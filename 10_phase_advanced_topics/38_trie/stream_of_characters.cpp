// Stream of Characters — https://leetcode.com/problems/stream-of-characters/
// Reverse-word trie; each query walks recent chars backward for a word end.
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

struct TrieNode {
    TrieNode* ch[26]{};
    bool end = false;
};

class StreamChecker {
    TrieNode* root = new TrieNode();
    std::deque<char> hist;
    int maxLen = 0;

  public:
    explicit StreamChecker(const std::vector<std::string>& words) {
        for (const auto& w : words) {
            maxLen = std::max(maxLen, static_cast<int>(w.size()));
            TrieNode* cur = root;
            for (int i = static_cast<int>(w.size()) - 1; i >= 0; --i) {
                int c = w[static_cast<size_t>(i)] - 'a';
                if (!cur->ch[c])
                    cur->ch[c] = new TrieNode();
                cur = cur->ch[c];
            }
            cur->end = true;
        }
    }

    bool query(char letter) {
        hist.push_front(letter);
        if (static_cast<int>(hist.size()) > maxLen)
            hist.pop_back();
        TrieNode* cur = root;
        for (char c : hist) {
            int i = c - 'a';
            if (!cur->ch[i])
                return false;
            cur = cur->ch[i];
            if (cur->end)
                return true;
        }
        return false;
    }
};

int main() {
    StreamChecker sc({"cd", "f", "kl"});
    for (char c : std::string("abcd"))
        std::cout << std::boolalpha << sc.query(c) << " ";
    std::cout << "(expected false false false true)\n";
    return 0;
}
