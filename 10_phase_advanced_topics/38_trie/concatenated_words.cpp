// Concatenated Words — https://leetcode.com/problems/concatenated-words/
// Trie of dictionary + DFS word-break requiring at least two pieces.
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Node {
    Node* ch[26]{};
    bool end = false;
};

std::vector<std::string> findAllConcatenatedWordsInADict(const std::vector<std::string>& words) {
    Node* root = new Node();
    for (const auto& w : words) {
        if (w.empty())
            continue;
        Node* cur = root;
        for (char c : w) {
            int i = c - 'a';
            if (!cur->ch[i])
                cur->ch[i] = new Node();
            cur = cur->ch[i];
        }
        cur->end = true;
    }

    std::vector<std::string> ans;
    for (const auto& w : words) {
        if (w.empty())
            continue;
        int n = static_cast<int>(w.size());
        std::vector<int> memo(static_cast<size_t>(n), -1);
        std::function<bool(int, int)> dfs = [&](int i, int parts) -> bool {
            if (i == n)
                return parts >= 2;
            if (memo[static_cast<size_t>(i)] != -1 && parts > 0)
                return memo[static_cast<size_t>(i)];
            Node* cur = root;
            for (int j = i; j < n; ++j) {
                int c = w[static_cast<size_t>(j)] - 'a';
                if (!cur->ch[c])
                    break;
                cur = cur->ch[c];
                if (cur->end && dfs(j + 1, parts + 1)) {
                    if (parts > 0)
                        memo[static_cast<size_t>(i)] = 1;
                    return true;
                }
            }
            if (parts > 0)
                memo[static_cast<size_t>(i)] = 0;
            return false;
        };
        if (dfs(0, 0))
            ans.push_back(w);
    }
    return ans;
}

int main() {
    auto ans = findAllConcatenatedWordsInADict({"cat", "cats", "catsdogcats", "dog", "dogcatsdog",
                                                "hippopotamuses", "rat", "ratcatdogcat"});
    for (auto& s : ans)
        std::cout << s << " ";
    std::cout << "\n";
    return 0;
}
