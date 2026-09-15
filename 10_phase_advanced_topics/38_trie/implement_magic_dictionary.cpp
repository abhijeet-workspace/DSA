// Implement Magic Dictionary — https://leetcode.com/problems/implement-magic-dictionary/
// Trie DFS with a single allowed character mismatch.
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Node {
    Node* ch[26]{};
    bool end = false;
};

class MagicDictionary {
    Node* root = new Node();

  public:
    void buildDict(const std::vector<std::string>& dictionary) {
        for (const auto& w : dictionary) {
            Node* cur = root;
            for (char c : w) {
                int i = c - 'a';
                if (!cur->ch[i])
                    cur->ch[i] = new Node();
                cur = cur->ch[i];
            }
            cur->end = true;
        }
    }

    bool search(const std::string& searchWord) const {
        std::function<bool(Node*, int, bool)> dfs = [&](Node* node, int i, bool changed) -> bool {
            if (!node)
                return false;
            if (i == static_cast<int>(searchWord.size()))
                return changed && node->end;
            int c = searchWord[static_cast<size_t>(i)] - 'a';
            if (dfs(node->ch[c], i + 1, changed))
                return true;
            if (!changed) {
                for (int j = 0; j < 26; ++j)
                    if (j != c && dfs(node->ch[j], i + 1, true))
                        return true;
            }
            return false;
        };
        return dfs(root, 0, false);
    }
};

int main() {
    MagicDictionary md;
    md.buildDict({"hello", "leetcode"});
    std::cout << std::boolalpha << md.search("hello") << " (expected false)\n"
              << md.search("hhllo") << " (expected true)\n"
              << md.search("hell") << " (expected false)\n";
    return 0;
}
