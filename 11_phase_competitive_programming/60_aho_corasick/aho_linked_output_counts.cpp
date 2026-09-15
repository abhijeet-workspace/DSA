// Aho linked output counts — aggregate via fail-chain outCnt
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct AC {
    struct Node {
        std::array<int, 26> next{};
        int link = 0;
        int outCnt = 0;
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
        ++t[v].outCnt;
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
                t[u].outCnt += t[t[u].link].outCnt;
                q.push(u);
            }
        }
    }
    long long countAll(const std::string& text) const {
        long long ans = 0;
        int v = 0;
        for (char ch : text) {
            v = t[v].next[ch - 'a'];
            ans += t[v].outCnt;
        }
        return ans;
    }
};

int main() {
    AC ac;
    ac.insert("a");
    ac.insert("aa");
    ac.build();
    std::cout << "hits=" << ac.countAll("aaa") << " (expected 4)\n";
    return 0;
}
