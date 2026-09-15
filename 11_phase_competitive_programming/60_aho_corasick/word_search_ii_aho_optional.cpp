// Word Search II — LC 212 (trie + DFS; AC optional/not preferred on grids)
#include <iostream>
#include <string>
#include <vector>

struct Trie {
    Trie* next[26]{};
    std::string word;
};

void insert(Trie* root, const std::string& w) {
    Trie* cur = root;
    for (char ch : w) {
        int c = ch - 'a';
        if (!cur->next[c])
            cur->next[c] = new Trie();
        cur = cur->next[c];
    }
    cur->word = w;
}

void dfs(std::vector<std::vector<char>>& board, int i, int j, Trie* node,
         std::vector<std::string>& ans) {
    char ch = board[i][j];
    if (ch == '#' || !node->next[ch - 'a'])
        return;
    node = node->next[ch - 'a'];
    if (!node->word.empty()) {
        ans.push_back(node->word);
        node->word.clear();
    }
    board[i][j] = '#';
    static const int di[4] = {1, -1, 0, 0};
    static const int dj[4] = {0, 0, 1, -1};
    for (int d = 0; d < 4; ++d) {
        int ni = i + di[d], nj = j + dj[d];
        if (ni >= 0 && nj >= 0 && ni < (int)board.size() && nj < (int)board[0].size())
            dfs(board, ni, nj, node, ans);
    }
    board[i][j] = ch;
}

std::vector<std::string> findWords(std::vector<std::vector<char>> board,
                                   const std::vector<std::string>& words) {
    Trie* root = new Trie();
    for (const auto& w : words)
        insert(root, w);
    std::vector<std::string> ans;
    for (int i = 0; i < (int)board.size(); ++i)
        for (int j = 0; j < (int)board[0].size(); ++j)
            dfs(board, i, j, root, ans);
    return ans;
}

int main() {
    auto board = std::vector<std::vector<char>>{
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'},
    };
    auto ans = findWords(board, {"oath", "pea", "eat", "rain"});
    for (auto& s : ans)
        std::cout << s << " ";
    std::cout << "(expected oath eat — order may vary)\n";
    return 0;
}
