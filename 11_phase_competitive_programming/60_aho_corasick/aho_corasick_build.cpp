// Aho-Corasick build + match exists — CP classic
// Trie + failure links; report which patterns occur in text.
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
                u = 0; // missing root edge → stay at root
            } else {
                t[static_cast<size_t>(u)].link = 0;
                q.push(u);
            }
        }
        while (!q.empty()) {
            const int v = q.front();
            q.pop();
            for (int c = 0; c < 26; ++c) {
                int u = t[static_cast<size_t>(v)].next[static_cast<size_t>(c)];
                if (u == -1) {
                    t[static_cast<size_t>(v)].next[static_cast<size_t>(c)] =
                        t[static_cast<size_t>(t[static_cast<size_t>(v)].link)]
                            .next[static_cast<size_t>(c)];
                    continue;
                }
                t[static_cast<size_t>(u)].link =
                    t[static_cast<size_t>(t[static_cast<size_t>(v)].link)]
                        .next[static_cast<size_t>(c)];
                const auto& from =
                    t[static_cast<size_t>(t[static_cast<size_t>(u)].link)].outs;
                t[static_cast<size_t>(u)].outs.insert(
                    t[static_cast<size_t>(u)].outs.end(), from.begin(), from.end());
                q.push(u);
            }
        }
    }

    std::vector<char> findIn(const std::string& text, int nPat) const {
        std::vector<char> seen(static_cast<size_t>(nPat), 0);
        int v = 0;
        for (char ch : text) {
            v = t[static_cast<size_t>(v)].next[static_cast<size_t>(ch - 'a')];
            for (int id : t[static_cast<size_t>(v)].outs) {
                seen[static_cast<size_t>(id)] = 1;
            }
        }
        return seen;
    }
};

int main() {
    const std::vector<std::string> pats = {"he", "she", "his", "hers"};
    AC ac;
    for (int i = 0; i < static_cast<int>(pats.size()); ++i) {
        ac.insert(pats[static_cast<size_t>(i)], i);
    }
    ac.build();
    const auto seen = ac.findIn("ushers", static_cast<int>(pats.size()));
    std::cout << "he=" << int(seen[0]) << " she=" << int(seen[1])
              << " hers=" << int(seen[3]) << " (expected 1 1 1)\n";
    return 0;
}
