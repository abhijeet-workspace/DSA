// Word Filter — https://leetcode.com/problems/prefix-and-suffix-search/
// Insert every suffix+"#"+word; query suffix+"#"+prefix for max index.
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class WordFilter {
    struct Node {
        std::unordered_map<char, Node*> ch;
        int weight = -1;
    };
    Node* root = new Node();

    void insert(const std::string& key, int w) {
        Node* cur = root;
        for (char c : key) {
            if (!cur->ch.count(c)) cur->ch[c] = new Node();
            cur = cur->ch[c];
            cur->weight = w;
        }
    }

public:
    explicit WordFilter(const std::vector<std::string>& words) {
        for (int i = 0; i < static_cast<int>(words.size()); ++i) {
            const std::string& w = words[static_cast<size_t>(i)];
            for (int j = 0; j <= static_cast<int>(w.size()); ++j)
                insert(w.substr(static_cast<size_t>(j)) + "#" + w, i);
        }
    }

    int f(const std::string& pref, const std::string& suff) {
        Node* cur = root;
        for (char c : suff + "#" + pref) {
            if (!cur->ch.count(c)) return -1;
            cur = cur->ch[c];
        }
        return cur->weight;
    }
};

int main() {
    WordFilter wf({"apple"});
    std::cout << wf.f("a", "e") << " (expected 0)\n"
              << wf.f("b", "") << " (expected -1)\n";
    return 0;
}
