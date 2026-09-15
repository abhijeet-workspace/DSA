// Palindrome Pairs — https://leetcode.com/problems/palindrome-pairs/
// Reverse-word trie; partners make word[i]+word[j] a palindrome.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Node {
    Node* ch[26]{};
    int idx = -1;
    std::vector<int> palBelow;
};

bool isPal(const std::string& s, int l, int r) {
    while (l < r)
        if (s[static_cast<size_t>(l++)] != s[static_cast<size_t>(r--)])
            return false;
    return true;
}

std::vector<std::vector<int>> palindromePairs(const std::vector<std::string>& words) {
    Node* root = new Node();
    for (int id = 0; id < static_cast<int>(words.size()); ++id) {
        const std::string& w = words[static_cast<size_t>(id)];
        Node* cur = root;
        for (int i = static_cast<int>(w.size()) - 1; i >= 0; --i) {
            if (isPal(w, 0, i))
                cur->palBelow.push_back(id);
            int c = w[static_cast<size_t>(i)] - 'a';
            if (!cur->ch[c])
                cur->ch[c] = new Node();
            cur = cur->ch[c];
        }
        cur->palBelow.push_back(id);
        cur->idx = id;
    }

    std::vector<std::vector<int>> ans;
    for (int i = 0; i < static_cast<int>(words.size()); ++i) {
        const std::string& w = words[static_cast<size_t>(i)];
        Node* cur = root;
        bool ok = true;
        for (int j = 0; j < static_cast<int>(w.size()); ++j) {
            if (cur->idx >= 0 && cur->idx != i && isPal(w, j, static_cast<int>(w.size()) - 1))
                ans.push_back({i, cur->idx});
            int c = w[static_cast<size_t>(j)] - 'a';
            if (!cur->ch[c]) {
                ok = false;
                break;
            }
            cur = cur->ch[c];
        }
        if (ok) {
            for (int id : cur->palBelow)
                if (id != i)
                    ans.push_back({i, id});
        }
    }
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    return ans;
}

int main() {
    for (auto& p : palindromePairs({"bat", "tab", "cat"}))
        std::cout << "(" << p[0] << "," << p[1] << ") ";
    std::cout << "(expected (0,1) (1,0))\n";
    return 0;
}
