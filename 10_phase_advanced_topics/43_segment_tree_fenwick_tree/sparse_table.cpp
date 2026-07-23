// Sparse table RMQ — static range minimum; build O(N log N), query O(1)
// st[k][i] = min on [i, i+2^k); query = min of two overlapping 2^floor(log) blocks
#include <iostream>
#include <vector>
#include <algorithm>

struct SparseTable {
    int n;
    std::vector<int> lg;
    std::vector<std::vector<int>> st;

    SparseTable(const std::vector<int>& a) {
        n = static_cast<int>(a.size());
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
        int K = lg[n] + 1;
        st.assign(K, std::vector<int>(n));
        st[0] = a;
        for (int k = 1; k < K; ++k)
            for (int i = 0; i + (1 << k) <= n; ++i)
                st[k][i] = std::min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }

    int query(int L, int R) const { // inclusive
        int k = lg[R - L + 1];
        return std::min(st[k][L], st[k][R - (1 << k) + 1]);
    }
};

int main() {
    std::vector<int> a = {1, 3, -2, 8, 5, -4, 7};
    SparseTable st(a);
    std::cout << "RMQ[1,4]=" << st.query(1, 4) << " (expected -2)\n";
    std::cout << "RMQ[0,6]=" << st.query(0, 6) << " (expected -4)\n";
    return 0;
}
