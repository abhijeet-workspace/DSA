// Fenwick / BIT — point update + prefix/range sum in O(log N)
// tree[i] covers (i - lsb(i), i]; walk via i += i & -i / i -= i & -i
#include <iostream>
#include <vector>

class FenwickTree1D {
    int n;
    std::vector<int> tree;

public:
    FenwickTree1D(int size) : n(size) { tree.assign(n + 1, 0); }

    void add(int i, int val) { // 1-indexed point update
        for (; i <= n; i += i & -i) tree[i] += val;
    }

    int query(int i) { // prefix sum [1..i]
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    int rangeQuery(int l, int r) { return query(r) - query(l - 1); }
};

class FenwickTree2D {
    int rows, cols;
    std::vector<std::vector<int>> tree;

public:
    FenwickTree2D(int r, int c) : rows(r), cols(c) {
        tree.assign(rows + 1, std::vector<int>(cols + 1, 0));
    }

    void add(int r, int c, int val) {
        for (int i = r; i <= rows; i += i & -i)
            for (int j = c; j <= cols; j += j & -j)
                tree[i][j] += val;
    }

    int query(int r, int c) {
        int sum = 0;
        for (int i = r; i > 0; i -= i & -i)
            for (int j = c; j > 0; j -= j & -j)
                sum += tree[i][j];
        return sum;
    }

    int rangeQuery(int r1, int c1, int r2, int c2) {
        return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) +
               query(r1 - 1, c1 - 1);
    }
};

int main() {
    std::vector<int> nums = {1, 7, 3, 0, 5, 8, 3};
    int n = static_cast<int>(nums.size());
    FenwickTree1D bit1d(n);
    for (int i = 0; i < n; ++i) bit1d.add(i + 1, nums[i]);

    std::cout << "Sum[2,5]=" << bit1d.rangeQuery(2, 5) << " (expected 15)\n";
    bit1d.add(3, 2); // nums[2] 3 -> 5
    std::cout << "Sum[2,5]=" << bit1d.rangeQuery(2, 5) << " (expected 17)\n";

    FenwickTree2D bit2d(3, 3);
    int v = 1;
    for (int r = 1; r <= 3; ++r)
        for (int c = 1; c <= 3; ++c) bit2d.add(r, c, v++);
    std::cout << "Subgrid[2..3][2..3]=" << bit2d.rangeQuery(2, 2, 3, 3)
              << " (expected 28)\n";
    return 0;
}
