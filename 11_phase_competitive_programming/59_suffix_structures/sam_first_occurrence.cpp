// SAM — First Occurrence Position
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct State {
    int len = 0, link = -1, firstPos = -1;
    std::map<char, int> next;
};

struct SAM {
    std::vector<State> st;
    int last = 0;
    SAM() { st.push_back(State()); }
    void extend(char c, int pos) {
        int cur = static_cast<int>(st.size());
        st.push_back(State());
        st[cur].len = st[last].len + 1;
        st[cur].firstPos = pos;
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
                // firstPos stays from q
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    int firstOccurrence(const std::string& pat) const {
        int v = 0;
        for (char c : pat) {
            auto it = st[v].next.find(c);
            if (it == st[v].next.end())
                return -1;
            v = it->second;
        }
        return st[v].firstPos - static_cast<int>(pat.size()) + 1;
    }
};

int main() {
    std::string s = "banana";
    SAM sam;
    for (int i = 0; i < static_cast<int>(s.size()); ++i)
        sam.extend(s[i], i);
    std::cout << sam.firstOccurrence("ana") << " (expected 1)\n";
    std::cout << sam.firstOccurrence("nana") << " (expected 2)\n";
    std::cout << sam.firstOccurrence("band") << " (expected -1)\n";
    return 0;
}
