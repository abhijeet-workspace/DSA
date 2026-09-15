// Maximum Level Sum of a Binary Tree —
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
#include <climits>
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxLevelSum(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    int level = 1, bestLvl = 1, bestSum = INT_MIN;
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        int sum = 0;
        for (int i = 0; i < sz; ++i) {
            TreeNode* u = q.front();
            q.pop();
            sum += u->val;
            if (u->left)
                q.push(u->left);
            if (u->right)
                q.push(u->right);
        }
        if (sum > bestSum) {
            bestSum = sum;
            bestLvl = level;
        }
        ++level;
    }
    return bestLvl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    std::cout << maxLevelSum(root) << " (expected 2)\n";
    return 0;
}
