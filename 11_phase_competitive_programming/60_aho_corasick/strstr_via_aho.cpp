// strStr via Aho-Corasick — LC 28 (pedagogical overkill for 1 pattern)
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct AC {
    struct Node {
        std::array<int, 26> next{};
        int link = 0;
        int outLen = 0; // pattern length ending here (0 if none)
        Node() { next.fill(-1); }
    };
    std::vector<Node> t;
    AC() { t.push_back(Node()); }

    void insert(const std::string& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = (int)t.size();
                t.push_back(Node());
            }
            v = t[v].next[c];
        }
        t[v].outLen = (int)s.size();
    }

    void build() {
        std::queue<int> q;
        for (int c = 0; c < 26; ++c) {
            int& u = t[0].next[c];
            if (u == -1)
                u = 0;
            else {
                t[u].link = 0;
                q.push(u);
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int c = 0; c < 26; ++c) {
                int u = t[v].next[c];
                if (u == -1) {
                    t[v].next[c] = t[t[v].link].next[c];
                    continue;
                }
                t[u].link = t[t[v].link].next[c];
                if (!t[u].outLen)
                    t[u].outLen = t[t[u].link].outLen;
                q.push(u);
            }
        }
    }

    int firstIndex(const std::string& text) const {
        int v = 0;
        for (int i = 0; i < (int)text.size(); ++i) {
            v = t[v].next[text[i] - 'a'];
            if (t[v].outLen)
                return i - t[v].outLen + 1;
        }
        return -1;
    }
};

int main() {
    AC ac;
    ac.insert("sad");
    ac.build();
    std::cout << "idx=" << ac.firstIndex("sadbutsad") << " (expected 0)\n";
    AC ac2;
    ac2.insert("leeto");
    ac2.build();
    std::cout << "idx=" << ac2.firstIndex("leetcode") << " (expected -1)\n";
    return 0;
}
