// Huffman Encoding — optimal prefix-free codes via min-heap merges
// Classic greedy compression (no LeetCode id).
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

struct HuffNode {
    char ch;
    int freq;
    HuffNode* left;
    HuffNode* right;
    HuffNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    HuffNode(int f, HuffNode* l, HuffNode* r) : ch('\0'), freq(f), left(l), right(r) {}
};

void collect(HuffNode* root, const std::string& code,
             std::vector<std::pair<char, std::string>>& out) {
    if (!root) return;
    if (!root->left && !root->right) {
        out.push_back({root->ch, code.empty() ? "0" : code}); // single-symbol edge
        return;
    }
    collect(root->left, code + "0", out);
    collect(root->right, code + "1", out);
}

std::vector<std::pair<char, std::string>> huffmanCodes(const std::string& text) {
    std::unordered_map<char, int> freq;
    for (char c : text) ++freq[c];
    auto cmp = [](HuffNode* a, HuffNode* b) { return a->freq > b->freq; };
    std::priority_queue<HuffNode*, std::vector<HuffNode*>, decltype(cmp)> pq(cmp);
    for (const auto& [ch, f] : freq) pq.push(new HuffNode(ch, f));
    while (pq.size() > 1) {
        HuffNode* L = pq.top(); pq.pop();
        HuffNode* R = pq.top(); pq.pop();
        pq.push(new HuffNode(L->freq + R->freq, L, R)); // merge two lightest
    }
    std::vector<std::pair<char, std::string>> out;
    collect(pq.top(), "", out);
    return out;
}

int main() {
    auto codes = huffmanCodes("aabbbcc");
    std::cout << "symbols=" << codes.size() << " (expected 3)\n";
    for (const auto& [ch, code] : codes) {
        std::cout << "  " << ch << " -> " << code << "\n";
    }
    return 0;
}
