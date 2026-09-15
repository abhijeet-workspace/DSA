// Design Search Autocomplete System — https://leetcode.com/problems/design-search-autocomplete-system/
// Trie of sentences with hot degrees; input(c) returns top-3 hot prefix matches ('#' commits).
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class AutocompleteSystem {
    struct Node {
        std::unordered_map<char, Node*> next;
        std::unordered_map<std::string, int> hot; // sentence -> times (stored at nodes along path)
        ~Node() {
            for (auto& [c, ch] : next) {
                (void)c;
                delete ch;
            }
        }
    };

    Node* root_;
    Node* curr_;
    std::string prefix_;

    void add(const std::string& s, int t) {
        Node* node = root_;
        for (char c : s) {
            if (!node->next.count(c)) {
                node->next[c] = new Node();
            }
            node = node->next[c];
            node->hot[s] += t;
        }
    }

    std::vector<std::string> top3(Node* node) {
        if (!node) {
            return {};
        }
        std::vector<std::pair<int, std::string>> items;
        for (const auto& [sent, times] : node->hot) {
            items.push_back({-times, sent}); // hot desc, then lex asc via string
        }
        std::sort(items.begin(), items.end());
        std::vector<std::string> res;
        for (int i = 0; i < static_cast<int>(items.size()) && i < 3; ++i) {
            res.push_back(items[static_cast<size_t>(i)].second);
        }
        return res;
    }

public:
    AutocompleteSystem(const std::vector<std::string>& sentences, const std::vector<int>& times)
        : root_(new Node()), curr_(root_) {
        for (size_t i = 0; i < sentences.size(); ++i) {
            add(sentences[i], times[i]);
        }
    }

    ~AutocompleteSystem() { delete root_; }

    std::vector<std::string> input(char c) {
        if (c == '#') {
            add(prefix_, 1);
            prefix_.clear();
            curr_ = root_;
            return {};
        }
        prefix_.push_back(c);
        if (curr_ && curr_->next.count(c)) {
            curr_ = curr_->next[c];
            return top3(curr_);
        }
        curr_ = nullptr;
        return {};
    }
};

int main() {
    AutocompleteSystem ac({"i love you", "island", "iroman", "i love leetcode"}, {5, 3, 2, 2});
    auto print = [](const std::vector<std::string>& v) {
        for (size_t i = 0; i < v.size(); ++i) {
            if (i) std::cout << " | ";
            std::cout << v[i];
        }
        std::cout << '\n';
    };
    print(ac.input('i')); // i love you, island, i love leetcode
    std::cout << "(expected i love you | island | i love leetcode)\n";
    print(ac.input(' '));
    std::cout << "(expected i love you | i love leetcode)\n";
    print(ac.input('a'));
    std::cout << "(expected empty)\n";
    print(ac.input('#'));
    std::cout << "(expected empty after commit)\n";
    return 0;
}
