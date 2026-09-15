// SAM — Number of Distinct Substrings
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct State {
    int len = 0, link = -1;
    std::map<char, int> next;
};

struct SAM {
    std::vector<State> st;
    int last = 0;
    SAM() { st.push_back(State()); }
    void extend(char c) {
        int cur = static_cast<int>(st.size());
        st.push_back(State());
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1)
            st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else {
                int clone = static_cast<int>(st.size());
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    long long distinct() const {
        long long ans = 0;
        for (size_t i = 1; i < st.size(); ++i)
            ans += st[i].len - st[st[i].link].len;
        return ans;
    }
};

int main() {
    SAM sam;
    for (char c : std::string("aba"))
        sam.extend(c);
    std::cout << sam.distinct() << " (expected 5)\n";
    return 0;
}
