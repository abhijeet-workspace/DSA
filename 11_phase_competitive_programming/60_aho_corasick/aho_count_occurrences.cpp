// Aho-Corasick count occurrences — CP classic
// Each visit adds outCnt (own + inherited via failure links).
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
            const int c = ch - 'a';
            if (t[static_cast<size_t>(v)].next[static_cast<size_t>(c)] == -1) {
                t[static_cast<size_t>(v)].next[static_cast<size_t>(c)] =
                    static_cast<int>(t.size());
                t.push_back(Node());
            }
            v = t[static_cast<size_t>(v)].next[static_cast<size_t>(c)];
        }
        ++t[static_cast<size_t>(v)].outCnt;
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
            t[static_cast<size_t>(v)].outCnt +=
                t[static_cast<size_t>(t[static_cast<size_t>(v)].link)].outCnt;
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

    long long countAll(const std::string& text) const {
        long long ans = 0;
        int v = 0;
        for (char ch : text) {
            v = t[static_cast<size_t>(v)].next[static_cast<size_t>(ch - 'a')];
            ans += t[static_cast<size_t>(v)].outCnt;
        }
        return ans;
    }
};

int main() {
    AC ac;
    ac.insert("a");
    ac.insert("aa");
    ac.build();
    std::cout << ac.countAll("aaa") << " (expected 5)\n";
    return 0;
}
