// Suffix Tree — teaching demo via inserting all suffixes (O(N²) build)
// Enough to show O(M) pattern existence checks after the tree exists.
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct SuffixNode {
    std::unordered_map<char, SuffixNode*> next;
    bool end = false;
};

class SuffixTree {
  public:
    SuffixTree() : root_(new SuffixNode()) {}

    ~SuffixTree() { destroy(root_); }

    SuffixTree(const SuffixTree&) = delete;
    SuffixTree& operator=(const SuffixTree&) = delete;

    void build(const std::string& text) {
        text_ = text;
        for (int i = 0; i < static_cast<int>(text.size()); ++i) {
            insertSuffix(text.substr(static_cast<size_t>(i)));
        }
    }

    bool contains(const std::string& pat) const {
        SuffixNode* cur = root_;
        for (char ch : pat) {
            auto it = cur->next.find(ch);
            if (it == cur->next.end())
                return false;
            cur = it->second;
        }
        return true;
    }

  private:
    SuffixNode* root_;
    std::string text_;

    void insertSuffix(const std::string& s) {
        SuffixNode* cur = root_;
        for (char ch : s) {
            if (!cur->next.count(ch))
                cur->next[ch] = new SuffixNode();
            cur = cur->next[ch];
        }
        cur->end = true;
    }

    void destroy(SuffixNode* node) {
        if (!node)
            return;
        for (auto& [_, child] : node->next)
            destroy(child);
        delete node;
    }
};

int main() {
    SuffixTree st;
    st.build("banana");
    std::cout << "ana? " << (st.contains("ana") ? "yes" : "no") << "\n";
    std::cout << "nan? " << (st.contains("nan") ? "yes" : "no") << "\n";
    std::cout << "band? " << (st.contains("band") ? "yes" : "no") << "\n";
    std::cout << "a? " << (st.contains("a") ? "yes" : "no") << "\n";
    return 0;
}
