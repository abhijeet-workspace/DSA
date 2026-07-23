// Aho-Corasick first match positions — CP classic
// Record leftmost start index per pattern (or -1).
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
    std::vector<int> plen;

    AC() { t.push_back(Node()); }

    void insert(const std::string& s, int id) {
        if (static_cast<int>(plen.size()) <= id) {
            plen.resize(static_cast<size_t>(id) + 1);
        }
        plen[static_cast<size_t>(id)] = static_cast<int>(s.size());
        int v = 0;
        for (char ch : s) {
            const int c = ch - 'a';
            if (t[static_cast<size_t>(v)].next[static_cast<size_t>(c)] == -1) {
                t[static_cast<size_t>(v)].next[static_cast<size_t>(c)] =
                    static_cast<int>(t.size());
                t.push_back(Node());
            }
            v = t[static_cast<size_t>(v)].next[static_cast<size_t>(c)];
        }
        t[static_cast<size_t>(v)].outs.push_back(id);
    }

    void build() {
        std::queue<int> q;
        for (int c = 0; c < 26; ++c) {
            int& u = t[0].next[static_cast<size_t>(c)];
            if (u == -1) {
                u = 0;
            } else {
                t[static_cast<size_t>(u)].link = 0;
                q.push(u);
            }
        }
        while (!q.empty()) {
            const int v = q.front();
            q.pop();
            for (int id : t[static_cast<size_t>(t[static_cast<size_t>(v)].link)].outs) {
                t[static_cast<size_t>(v)].outs.push_back(id);
            }
            for (int c = 0; c < 26; ++c) {
                const int u = t[static_cast<size_t>(v)].next[static_cast<size_t>(c)];
                if (u == -1) {
                    t[static_cast<size_t>(v)].next[static_cast<size_t>(c)] =
                        t[static_cast<size_t>(t[static_cast<size_t>(v)].link)]
                            .next[static_cast<size_t>(c)];
                    continue;
                }
                t[static_cast<size_t>(u)].link =
                    t[static_cast<size_t>(t[static_cast<size_t>(v)].link)]
                        .next[static_cast<size_t>(c)];
                q.push(u);
            }
        }
    }

    std::vector<int> firstPos(const std::string& text, int nPat) const {
        std::vector<int> ans(static_cast<size_t>(nPat), -1);
        int v = 0;
        for (int i = 0; i < static_cast<int>(text.size()); ++i) {
            v = t[static_cast<size_t>(v)].next[static_cast<size_t>(text[static_cast<size_t>(i)] - 'a')];
            for (int id : t[static_cast<size_t>(v)].outs) {
                if (ans[static_cast<size_t>(id)] == -1) {
                    ans[static_cast<size_t>(id)] = i - plen[static_cast<size_t>(id)] + 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    AC ac;
    ac.insert("ab", 0);
    ac.insert("ba", 1);
    ac.build();
    const auto p = ac.firstPos("abab", 2);
    std::cout << p[0] << " " << p[1] << " (expected 0 1)\n";
    return 0;
}
