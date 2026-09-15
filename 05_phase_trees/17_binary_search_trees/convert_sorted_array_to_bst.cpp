// Convert Sorted Array to Binary Search Tree — https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(const std::vector<int>& a, int lo, int hi) {
    if (lo > hi) return nullptr;
    const int mid = lo + (hi - lo) / 2;
    TreeNode* n = new TreeNode(a[mid]);
    n->left = build(a, lo, mid - 1);
    n->right = build(a, mid + 1, hi);
    return n;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return build(nums, 0, static_cast<int>(nums.size()) - 1);
}

int main() {
    std::vector<int> nums{-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);
    std::cout << root->val << " (expected 0)\n";
    return 0;
}
