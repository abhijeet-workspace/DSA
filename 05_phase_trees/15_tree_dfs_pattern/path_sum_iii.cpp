// Path Sum III — https://leetcode.com/problems/path-sum-iii/
#include <iostream>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int dfs(TreeNode* n, long long cur, int target,
        std::unordered_map<long long, int>& freq) {
    if (!n) {
        return 0;
    }
    cur += n->val;
    int ans = 0;
    auto it = freq.find(cur - target);
    if (it != freq.end()) {
        ans += it->second;
    }
    ++freq[cur];
    ans += dfs(n->left, cur, target, freq);
    ans += dfs(n->right, cur, target, freq);
    --freq[cur]; // backtrack
    return ans;
}

int pathSum(TreeNode* root, int targetSum) {
    std::unordered_map<long long, int> freq;
    freq[0] = 1; // empty prefix
    return dfs(root, 0, targetSum, freq);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    std::cout << pathSum(root, 8) << " (expected 3)\n";
    return 0;
}
