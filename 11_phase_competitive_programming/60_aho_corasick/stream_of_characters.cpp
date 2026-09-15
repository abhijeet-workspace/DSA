// Stream of Characters — LC 1032 (reversed trie; AC optional framing)
#include <iostream>
#include <string>
#include <vector>

struct StreamChecker {
    struct Node {
        Node* next[26]{};
        bool end = false;
    };
    Node* root = new Node();
    std::string buf;

    explicit StreamChecker(const std::vector<std::string>& words) {
        for (const auto& w : words) {
            Node* cur = root;
            for (int i = (int)w.size() - 1; i >= 0; --i) {
                int c = w[i] - 'a';
                if (!cur->next[c])
                    cur->next[c] = new Node();
                cur = cur->next[c];
            }
            cur->end = true;
        }
    }

    bool query(char letter) {
        buf.push_back(letter);
        Node* cur = root;
        for (int i = (int)buf.size() - 1; i >= 0; --i) {
            int c = buf[i] - 'a';
            if (!cur->next[c])
                return false;
            cur = cur->next[c];
            if (cur->end)
                return true;
        }
        return false;
    }
};

int main() {
    StreamChecker sc({"cd", "f", "kl"});
    std::cout << std::boolalpha;
    std::cout << sc.query('a') << " (expected false)\n";
    std::cout << sc.query('b') << " (expected false)\n";
    std::cout << sc.query('c') << " (expected false)\n";
    std::cout << sc.query('d') << " (expected true)\n";
    std::cout << sc.query('f') << " (expected true)\n";
    return 0;
}
