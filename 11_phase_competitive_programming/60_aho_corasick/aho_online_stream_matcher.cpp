// Aho online stream matcher — feed chars one-by-one
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
    int v = 0;
    AC() { t.push_back(Node()); }
    void insert(const std::string& s, int id) {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[u].next[c] == -1) {
                t[u].next[c] = (int)t.size();
                t.push_back(Node());
            }
            u = t[u].next[c];
        }
        t[u].outs.push_back(id);
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
            int x = q.front();
            q.pop();
            for (int c = 0; c < 26; ++c) {
                int u = t[x].next[c];
                if (u == -1) {
                    t[x].next[c] = t[t[x].link].next[c];
                    continue;
                }
                t[u].link = t[t[x].link].next[c];
                auto& from = t[t[u].link].outs;
                t[u].outs.insert(t[u].outs.end(), from.begin(), from.end());
                q.push(u);
            }
        }
    }
    std::vector<int> feed(char ch) {
        v = t[v].next[ch - 'a'];
        return t[v].outs;
    }
};

int main() {
    AC ac;
    ac.insert("ab", 0);
    ac.insert("bc", 1);
    ac.build();
    for (char ch : std::string("abc")) {
        auto hits = ac.feed(ch);
        std::cout << ch << " ->";
        for (int id : hits)
            std::cout << " " << id;
        std::cout << "\n";
    }
    return 0;
}
