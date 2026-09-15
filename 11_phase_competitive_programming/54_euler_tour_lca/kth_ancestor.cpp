// LC 1483 Kth Ancestor of a Tree Node — binary lifting
// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
#include <iostream>
#include <vector>

struct TreeAncestor {
    int LOG;
    std::vector<std::vector<int>> up;
    TreeAncestor(int n, std::vector<int> parent) {
        LOG = 1;
        while ((1 << LOG) <= n)
            ++LOG;
        up.assign(LOG, std::vector<int>(n, -1));
        up[0] = parent;
        for (int k = 1; k < LOG; ++k)
            for (int v = 0; v < n; ++v)
                if (up[k - 1][v] != -1)
                    up[k][v] = up[k - 1][up[k - 1][v]];
    }
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < LOG && node != -1; ++i)
            if (k & (1 << i))
                node = up[i][node];
        return node;
    }
};

int main() {
    TreeAncestor t(7, {-1, 0, 0, 1, 1, 2, 2});
    int a = t.getKthAncestor(3, 1);
    int b = t.getKthAncestor(5, 2);
    int c = t.getKthAncestor(6, 3);
    std::cout << a << " " << b << " " << c << "\n";
    bool ok = (a == 1 && b == 0 && c == -1);
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
