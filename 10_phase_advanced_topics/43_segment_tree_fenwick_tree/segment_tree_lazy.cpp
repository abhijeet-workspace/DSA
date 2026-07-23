// Segment tree + lazy propagation — range add, range sum in O(log N)
// lazy[node] = pending add for whole segment; push before split
#include <iostream>
#include <vector>

class SegmentTreeLazy {
    int n;
    std::vector<int> tree, lazy;

    void build(const std::vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    void updateRangeLazy(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = start + (end - start) / 2;
        updateRangeLazy(2 * node + 1, start, mid, l, r, val);
        updateRangeLazy(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int queryRangeLazy(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) return 0;
        push(node, start, end);
        if (start >= l && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        return queryRangeLazy(2 * node + 1, start, mid, l, r) +
               queryRangeLazy(2 * node + 2, mid + 1, end, l, r);
    }

public:
    SegmentTreeLazy(const std::vector<int>& arr) {
        n = static_cast<int>(arr.size());
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        if (n > 0) build(arr, 0, 0, n - 1);
    }

    void updateRange(int l, int r, int val) {
        if (n > 0) updateRangeLazy(0, 0, n - 1, l, r, val);
    }

    int queryRange(int l, int r) {
        if (n == 0) return 0;
        return queryRangeLazy(0, 0, n - 1, l, r);
    }
};

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTreeLazy seg(arr);
    std::cout << "Sum[1,3]=" << seg.queryRange(1, 3) << " (expected 15)\n";
    std::cout << "Sum[0,5]=" << seg.queryRange(0, 5) << " (expected 36)\n";

    seg.updateRange(1, 5, 10); // {1,13,15,17,19,21}
    std::cout << "Sum[1,3]=" << seg.queryRange(1, 3) << " (expected 45)\n";
    std::cout << "Sum[0,5]=" << seg.queryRange(0, 5) << " (expected 86)\n";
    std::cout << "Sum[0,0]=" << seg.queryRange(0, 0) << " (expected 1)\n";

    seg.updateRange(0, 2, -5); // {-4,8,10,17,19,21}
    std::cout << "Sum[0,2]=" << seg.queryRange(0, 2) << " (expected 14)\n";
    std::cout << "Sum[0,5]=" << seg.queryRange(0, 5) << " (expected 71)\n";
    return 0;
}
