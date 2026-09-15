// Aho fail-link walk lab — inspect links after build
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct AC {
    struct Node {
        std::array<int, 26> next{};
        int link = 0;
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
                q.push(u);
            }
        }
    }
};

int main() {
    AC ac;
    ac.insert("he");
    ac.insert("she");
    ac.build();
    for (int i = 0; i < (int)ac.t.size(); ++i)
        std::cout << "node " << i << " link " << ac.t[i].link << "\n";
    int v = 0;
    for (char ch : std::string("she"))
        v = ac.t[v].next[ch - 'a'];
    std::cout << "fail walk from state " << v << ":";
    for (int x = v;; x = ac.t[x].link) {
        std::cout << " " << x;
        if (x == 0)
            break;
    }
    std::cout << "\n";
    return 0;
}
