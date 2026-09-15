// Tree Isomorphism via Centroid Rooting — teaching lab
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct TreeIso {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> sz;
    TreeIso(int n_) : n(n_), g(n_ + 1), sz(n_ + 1) {}
    void addEdge(int u, int v) {
        g[static_cast<size_t>(u)].push_back(v);
        g[static_cast<size_t>(v)].push_back(u);
    }
    void dfsSize(int v, int p) {
        sz[static_cast<size_t>(v)] = 1;
        for (int to : g[static_cast<size_t>(v)])
            if (to != p) {
                dfsSize(to, v);
                sz[static_cast<size_t>(v)] += sz[static_cast<size_t>(to)];
            }
    }
    std::vector<int> centroids() {
        dfsSize(1, 0);
        int v = 1, p = 0;
        while (true) {
            int heavy = -1;
            for (int to : g[static_cast<size_t>(v)])
                if (to != p && sz[static_cast<size_t>(to)] > n / 2) {
                    heavy = to;
                    break;
                }
            if (heavy < 0)
                break;
            p = v;
            v = heavy;
        }
        std::vector<int> c = {v};
        for (int to : g[static_cast<size_t>(v)]) {
            int comp = (sz[static_cast<size_t>(to)] < sz[static_cast<size_t>(v)])
                           ? sz[static_cast<size_t>(to)]
                           : n - sz[static_cast<size_t>(v)];
            // neighbor component size when rooted at v:
            int toward = sz[static_cast<size_t>(to)];
            if (toward > sz[static_cast<size_t>(v)])
                toward = n - sz[static_cast<size_t>(v)];
            // verify second centroid via definition
        }
        // check neighbors for second centroid
        auto isCent = [&](int x) {
            for (int to : g[static_cast<size_t>(x)]) {
                std::vector<char> seen(static_cast<size_t>(n) + 1, 0);
                seen[static_cast<size_t>(x)] = 1;
                seen[static_cast<size_t>(to)] = 1;
                int cnt = 0;
                std::vector<int> st = {to};
                while (!st.empty()) {
                    int u = st.back();
                    st.pop_back();
                    ++cnt;
                    for (int w : g[static_cast<size_t>(u)])
                        if (!seen[static_cast<size_t>(w)]) {
                            seen[static_cast<size_t>(w)] = 1;
                            st.push_back(w);
                        }
                }
                if (cnt > n / 2)
                    return false;
            }
            return true;
        };
        c.clear();
        for (int x = 1; x <= n; ++x)
            if (isCent(x))
                c.push_back(x);
        return c;
    }
    std::string encode(int v, int p) {
        std::vector<std::string> ch;
        for (int to : g[static_cast<size_t>(v)])
            if (to != p)
                ch.push_back(encode(to, v));
        std::sort(ch.begin(), ch.end());
        std::string s = "(";
        for (auto& x : ch)
            s += x;
        s += ")";
        return s;
    }
    std::string canonical() {
        auto cents = centroids();
        std::vector<std::string> forms;
        for (int c : cents)
            forms.push_back(encode(c, 0));
        std::sort(forms.begin(), forms.end());
        return forms.empty() ? "" : forms[0];
    }
};

bool isomorphic(TreeIso& a, TreeIso& b) {
    if (a.n != b.n)
        return false;
    return a.canonical() == b.canonical();
}

int main() {
    TreeIso t1(4), t2(4), t3(4);
    t1.addEdge(1, 2);
    t1.addEdge(2, 3);
    t1.addEdge(2, 4);
    t2.addEdge(1, 3);
    t2.addEdge(3, 2);
    t2.addEdge(3, 4);
    t3.addEdge(1, 2);
    t3.addEdge(2, 3);
    t3.addEdge(3, 4);
    std::cout << (isomorphic(t1, t2) ? "yes" : "no") << " (expected yes)\n";
    std::cout << (isomorphic(t1, t3) ? "yes" : "no") << " (expected no)\n";
    return 0;
}
