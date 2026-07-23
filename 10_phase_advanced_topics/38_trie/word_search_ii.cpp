// Word Search II — https://leetcode.com/problems/word-search-ii/
// Trie of dictionary + board DFS; prune dead paths; clear word at leaf to dedupe.
#include <iostream>
#include <vector>
#include <string>

struct Node {
    Node* next[26]{};
    std::string word; // non-empty => complete word ends here
};

class Solution {
    Node* root = new Node();
    std::vector<std::string> ans;

    void insert(const std::string& w) {
        Node* cur = root;
        for (char c : w) {
            const int i = c - 'a';
            if (!cur->next[i]) cur->next[i] = new Node();
            cur = cur->next[i];
        }
        cur->word = w;
    }

    void dfs(std::vector<std::vector<char>>& board, int r, int c, Node* node) {
        const char ch = board[static_cast<size_t>(r)][static_cast<size_t>(c)];
        if (ch == '#' || !node->next[ch - 'a']) return;
        node = node->next[ch - 'a'];
        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word.clear(); // avoid duplicate finds
        }
        board[static_cast<size_t>(r)][static_cast<size_t>(c)] = '#'; // mark visited
        static const int dr[4] = {1, -1, 0, 0};
        static const int dc[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; ++k) {
            const int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nc >= 0 && nr < static_cast<int>(board.size())
                && nc < static_cast<int>(board[0].size())) {
                dfs(board, nr, nc, node);
            }
        }
        board[static_cast<size_t>(r)][static_cast<size_t>(c)] = ch; // restore
    }

public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> board,
                                       const std::vector<std::string>& words) {
        for (const auto& w : words) insert(w);
        for (int i = 0; i < static_cast<int>(board.size()); ++i) {
            for (int j = 0; j < static_cast<int>(board[0].size()); ++j) {
                dfs(board, i, j, root);
            }
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'},
    };
    auto res = Solution().findWords(board, {"oath", "pea", "eat", "rain"});
    std::cout << "found:";
    for (const auto& w : res) std::cout << " " << w;
    std::cout << " (expected eat oath)\n";
    return 0;
}
