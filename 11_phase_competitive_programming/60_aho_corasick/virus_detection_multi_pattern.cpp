// Virus detection multi-pattern — teaching lab (no invented contest ID)
// Statement: n signatures + text t; YES/NO if each signature occurs in t.
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
    std::vector<char> findIn(const std::string& text, int nPat) const {
        std::vector<char> seen(nPat, 0);
        int v = 0;
        for (char ch : text) {
            v = t[v].next[ch - 'a'];
            for (int id : t[v].outs)
                seen[id] = 1;
        }
        return seen;
    }
};

int main() {
    // Sample equivalent to: n=2; aba; ba; ababa
    std::vector<std::string> pats = {"aba", "ba"};
    std::string text = "ababa";
    AC ac;
    for (int i = 0; i < (int)pats.size(); ++i)
        ac.insert(pats[i], i);
    ac.build();
    auto seen = ac.findIn(text, (int)pats.size());
    for (int i = 0; i < (int)pats.size(); ++i)
        std::cout << (seen[i] ? "YES" : "NO") << "\n";
    return 0;
}
