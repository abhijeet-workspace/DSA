// Advanced Tries — XOR max-pair (LC 421) + Aho-Corasick skeleton
// Binary trie for max XOR; failure-link automaton for multi-pattern match.
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

class XORTrieNode {
public:
    XORTrieNode* children[2]{};
};

class XORTrie {
    XORTrieNode* root = new XORTrieNode();

public:
    void insert(int num) {
        XORTrieNode* curr = root;
        for (int i = 31; i >= 0; --i) { // MSB -> LSB
            const int bit = (num >> i) & 1;
            if (!curr->children[bit]) curr->children[bit] = new XORTrieNode();
            curr = curr->children[bit];
        }
    }

    int getMaxXOR(int num) {
        XORTrieNode* curr = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; --i) {
            const int bit = (num >> i) & 1;
            const int want = 1 - bit; // prefer opposite bit
            if (curr->children[want]) {
                maxXOR |= (1 << i);
                curr = curr->children[want];
            } else if (curr->children[bit]) {
                curr = curr->children[bit];
            } else {
                break;
            }
        }
        return maxXOR;
    }
};

int findMaximumXOR(const std::vector<int>& nums) {
    XORTrie trie;
    for (int num : nums) trie.insert(num);
    int maxXOR = 0;
    for (int num : nums) maxXOR = std::max(maxXOR, trie.getMaxXOR(num));
    return maxXOR;
}

class AhoCorasick {
    static const int ALPHABET = 26;
    struct Node {
        int children[ALPHABET]{};
        int failLink = 0;
        std::vector<int> patternsMatched;
    };
    std::vector<Node> trie;

public:
    AhoCorasick() { trie.push_back(Node()); } // root = 0

    void insert(const std::string& pattern, int id) {
        int u = 0;
        for (char c : pattern) {
            const int idx = c - 'a';
            if (trie[static_cast<size_t>(u)].children[idx] == 0) {
                trie[static_cast<size_t>(u)].children[idx] = static_cast<int>(trie.size());
                trie.push_back(Node());
            }
            u = trie[static_cast<size_t>(u)].children[idx];
        }
        trie[static_cast<size_t>(u)].patternsMatched.push_back(id);
    }

    void buildFailureLinks() {
        std::queue<int> q;
        for (int i = 0; i < ALPHABET; ++i) {
            const int u = trie[0].children[i];
            if (u != 0) {
                trie[static_cast<size_t>(u)].failLink = 0;
                q.push(u);
            }
        }
        while (!q.empty()) {
            const int u = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET; ++i) {
                const int v = trie[static_cast<size_t>(u)].children[i];
                if (v == 0) continue;
                int f = trie[static_cast<size_t>(u)].failLink;
                while (f > 0 && trie[static_cast<size_t>(f)].children[i] == 0) {
                    f = trie[static_cast<size_t>(f)].failLink;
                }
                trie[static_cast<size_t>(v)].failLink = trie[static_cast<size_t>(f)].children[i];
                auto& failMatches =
                    trie[static_cast<size_t>(trie[static_cast<size_t>(v)].failLink)].patternsMatched;
                auto& cur = trie[static_cast<size_t>(v)].patternsMatched;
                cur.insert(cur.end(), failMatches.begin(), failMatches.end());
                q.push(v);
            }
        }
    }
};

int main() {
    std::cout << "--- XOR Trie (Maximum XOR of Two Numbers) ---\n";
    const std::vector<int> nums = {3, 10, 5, 25, 2, 8};
    std::cout << "Max XOR Value: " << findMaximumXOR(nums)
              << " (Expected: 28, which is 5 ^ 25 = 28)\n\n";

    std::cout << "--- Aho-Corasick Automaton Built successfully ---\n";
    AhoCorasick ac;
    ac.insert("he", 0);
    ac.insert("she", 1);
    ac.insert("his", 2);
    ac.insert("hers", 3);
    ac.buildFailureLinks();
    std::cout << "Patterns inserted: \"he\", \"she\", \"his\", \"hers\". Failure links processed.\n";
    return 0;
}
