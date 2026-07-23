// Suffix Automaton — distinct substrings
// Online extend; count via sum (len - link_len) over states.
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct State {
    int len = 0;
    int link = -1;
    std::map<char, int> next;
};

struct SAM {
    std::vector<State> st;
    int last = 0;

    SAM() { st.push_back(State()); }

    void extend(char c) {
        const int cur = static_cast<int>(st.size());
        st.push_back(State());
        st[static_cast<size_t>(cur)].len = st[static_cast<size_t>(last)].len + 1;
        int p = last;
        while (p != -1 && !st[static_cast<size_t>(p)].next.count(c)) {
            st[static_cast<size_t>(p)].next[c] = cur;
            p = st[static_cast<size_t>(p)].link;
        }
        if (p == -1) {
            st[static_cast<size_t>(cur)].link = 0;
        } else {
            const int q = st[static_cast<size_t>(p)].next[c];
            if (st[static_cast<size_t>(p)].len + 1 == st[static_cast<size_t>(q)].len) {
                st[static_cast<size_t>(cur)].link = q;
            } else {
                const int clone = static_cast<int>(st.size());
                st.push_back(st[static_cast<size_t>(q)]); // copy transitions
                st[static_cast<size_t>(clone)].len = st[static_cast<size_t>(p)].len + 1;
                while (p != -1 && st[static_cast<size_t>(p)].next[c] == q) {
                    st[static_cast<size_t>(p)].next[c] = clone;
                    p = st[static_cast<size_t>(p)].link;
                }
                st[static_cast<size_t>(q)].link = st[static_cast<size_t>(cur)].link = clone;
            }
        }
        last = cur;
    }

    long long distinctSubstrings() const {
        long long ans = 0;
        for (size_t i = 1; i < st.size(); ++i) {
            ans += st[i].len - st[static_cast<size_t>(st[i].link)].len;
        }
        return ans;
    }
};

int main() {
    SAM sam;
    for (char c : std::string("ababa")) {
        sam.extend(c);
    }
    std::cout << sam.distinctSubstrings() << " (expected 9)\n";
    return 0;
}
