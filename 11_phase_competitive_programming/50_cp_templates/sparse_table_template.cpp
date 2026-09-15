// Sparse table template — static RMQ (min)
#include <cmath>
#include <iostream>
#include <vector>

struct SparseTable {
    int n, LOG;
    std::vector<std::vector<int>> st;
    std::vector<int> lg;
    explicit SparseTable(const std::vector<int>& a) : n(static_cast<int>(a.size())) {
        LOG = 32 - __builtin_clz(n);
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i / 2] + 1;
        st.assign(LOG, std::vector<int>(n));
        st[0] = a;
        for (int k = 1; k < LOG; ++k)
            for (int i = 0; i + (1 << k) <= n; ++i)
                st[k][i] = std::min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }
    int query(int l, int r) const { // inclusive
        int k = lg[r - l + 1];
        return std::min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

int main() {
    SparseTable st({4, 2, 3, 7, 1, 5});
    const int q = st.query(1, 4); // min(2,3,7,1)=1
    std::cout << "rmq[1,4]=" << q << " expected=1\n";
    std::cout << (q == 1 ? "OK\n" : "FAIL\n");
    return q == 1 ? 0 : 1;
}
