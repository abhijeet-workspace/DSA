// Multi-pattern search — Aho-Corasick teaching lab
#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct AC {
    struct Node {
        std::array<int, 26> next{};
        int link = 0;
        std::vector<int> outs;
        Node() { next.fill(-1); }
    };
    std::vector<Node> t;
    AC() { t.push_back(Node()); }
    void insert(const std::string& s, int id) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = (int)t.size();
                t.push_back(Node());
            }
            v = t[v].next[c];
        }
        t[v].outs.push_back(id);
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
                auto& from = t[t[u].link].outs;
                t[u].outs.insert(t[u].outs.end(), from.begin(), from.end());
                q.push(u);
            }
        }
    }
    std::vector<std::pair<int, int>> match(const std::string& text) const {
        std::vector<std::pair<int, int>> hits;
        int v = 0;
        for (int i = 0; i < (int)text.size(); ++i) {
            v = t[v].next[text[i] - 'a'];
            for (int id : t[v].outs)
                hits.push_back({id, i});
        }
        return hits;
    }
};

int main() {
    AC ac;
    ac.insert("he", 0);
    ac.insert("she", 1);
    ac.build();
    auto hits = ac.match("ushers");
    std::sort(hits.begin(), hits.end(), [](auto& a, auto& b) {
        return a.second != b.second ? a.second < b.second : a.first < b.first;
    });
    for (auto [id, pos] : hits)
        std::cout << "(" << id << "," << pos << ") ";
    std::cout << "\n";
    return 0;
}
