// Persistent SegTree range sum — CP classic
// Point add creates a new version; query any historical root.
#include <iostream>
#include <vector>

struct Node {
    long long sum = 0;
    int L = -1;
    int R = -1;
};

struct PersistSeg {
    std::vector<Node> t;
    int n;

    explicit PersistSeg(int n_) : n(n_) { t.push_back(Node()); }

    int newNode(Node x = {}) {
        t.push_back(x);
        return static_cast<int>(t.size()) - 1;
    }

    int build(int l, int r) {
        const int v = newNode();
        if (l == r) {
            return v;
        }
        const int m = (l + r) / 2;
        t[static_cast<size_t>(v)].L = build(l, m);
        t[static_cast<size_t>(v)].R = build(m + 1, r);
        return v;
    }

    int upd(int prev, int l, int r, int idx, long long add) {
        const int v = newNode(t[static_cast<size_t>(prev)]);
        t[static_cast<size_t>(v)].sum = t[static_cast<size_t>(prev)].sum + add;
        if (l != r) {
            const int m = (l + r) / 2;
            if (idx <= m) {
                t[static_cast<size_t>(v)].L =
                    upd(t[static_cast<size_t>(prev)].L, l, m, idx, add);
            } else {
                t[static_cast<size_t>(v)].R =
                    upd(t[static_cast<size_t>(prev)].R, m + 1, r, idx, add);
            }
        }
        return v;
    }

    long long query(int v, int l, int r, int ql, int qr) const {
        if (v < 0 || qr < l || r < ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return t[static_cast<size_t>(v)].sum;
        }
        const int m = (l + r) / 2;
        return query(t[static_cast<size_t>(v)].L, l, m, ql, qr) +
               query(t[static_cast<size_t>(v)].R, m + 1, r, ql, qr);
    }
};

int main() {
    const int n = 4;
    PersistSeg st(n);
    const int root0 = st.build(1, n);
    const int root1 = st.upd(root0, 1, n, 2, 5);
    const int root2 = st.upd(root1, 1, n, 2, 3);
    std::cout << st.query(root0, 1, n, 2, 2) << " (expected 0)\n";
    std::cout << st.query(root1, 1, n, 2, 2) << " (expected 5)\n";
    std::cout << st.query(root2, 1, n, 2, 2) << " (expected 8)\n";
    return 0;
}
