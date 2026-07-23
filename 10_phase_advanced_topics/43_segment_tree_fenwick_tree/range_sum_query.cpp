// Range Sum Query — Mutable (LeetCode 307): segment tree point update + range sum
// tree[node] = sum of [start..end]; children at 2*node, 2*node+1 (1-based heap)
#include <iostream>
#include <vector>

class NumArray {
    int n;
    std::vector<int> tree;

    void build(const std::vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void updateVal(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) updateVal(2 * node, start, mid, idx, val);
        else updateVal(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int sumRangeQuery(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;           // no overlap
        if (l <= start && end <= r) return tree[node]; // full cover
        int mid = start + (end - start) / 2;
        return sumRangeQuery(2 * node, start, mid, l, r) +
               sumRangeQuery(2 * node + 1, mid + 1, end, l, r);
    }

public:
    NumArray(std::vector<int>& nums) {
        n = static_cast<int>(nums.size());
        if (n > 0) {
            tree.resize(4 * n, 0);
            build(nums, 1, 0, n - 1);
        }
    }

    void update(int index, int val) {
        if (n > 0) updateVal(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return sumRangeQuery(1, 0, n - 1, left, right);
    }
};

int main() {
    std::vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    std::cout << "Sum(0,2)=" << numArray.sumRange(0, 2) << " (expected 9)\n";
    numArray.update(1, 2);
    std::cout << "Sum(0,2)=" << numArray.sumRange(0, 2) << " (expected 8)\n";
    return 0;
}
