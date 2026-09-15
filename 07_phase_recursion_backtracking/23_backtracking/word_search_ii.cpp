// Word Search II — https://leetcode.com/problems/word-search-ii/
// Find all words from words that can be formed on the board by adjacent letters.
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct TrieNode {
    std::unordered_map<char, TrieNode*> next;
    std::string word;
    ~TrieNode() {
        for (auto& [_, c] : next)
            delete c;
    }
};

void insert(TrieNode* root, const std::string& w) {
    TrieNode* cur = root;
    for (char c : w) {
        if (!cur->next.count(c))
            cur->next[c] = new TrieNode();
        cur = cur->next[c];
    }
    cur->word = w;
}

void dfs(std::vector<std::vector<char>>& board, int r, int c, TrieNode* node,
         std::vector<std::string>& found) {
    const int R = static_cast<int>(board.size());
    const int C = static_cast<int>(board[0].size());
    if (r < 0 || c < 0 || r >= R || c >= C)
        return;
    char ch = board[static_cast<size_t>(r)][static_cast<size_t>(c)];
    if (ch == '#' || !node->next.count(ch))
        return;
    node = node->next[ch];
    if (!node->word.empty()) {
        found.push_back(node->word);
        node->word.clear(); // dedupe
    }
    board[static_cast<size_t>(r)][static_cast<size_t>(c)] = '#';
    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};
    for (int k = 0; k < 4; ++k)
        dfs(board, r + dr[k], c + dc[k], node, found);
    board[static_cast<size_t>(r)][static_cast<size_t>(c)] = ch;
}

std::vector<std::string> findWords(std::vector<std::vector<char>> board,
                                   const std::vector<std::string>& words) {
    TrieNode root;
    for (const auto& w : words)
        insert(&root, w);
    std::vector<std::string> found;
    for (int i = 0; i < static_cast<int>(board.size()); ++i) {
        for (int j = 0; j < static_cast<int>(board[0].size()); ++j) {
            dfs(board, i, j, &root, found);
        }
    }
    return found;
}

int main() {
    std::vector<std::vector<char>> board = {
        {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    const auto r = findWords(board, {"oath", "pea", "eat", "rain"});
    std::cout << "count=" << r.size() << " (expected 2)\n";
    for (const auto& w : r)
        std::cout << w << "\n";
    return 0;
}
