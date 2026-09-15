// Deepest Leaves Sum — https://leetcode.com/problems/deepest-leaves-sum/
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int deepestLeavesSum(TreeNode* root) {
    if (!root)
        return 0;
    std::queue<TreeNode*> q;
    q.push(root);
    int sum = 0;
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        sum = 0;
        for (int i = 0; i < sz; ++i) {
            TreeNode* u = q.front();
            q.pop();
            sum += u->val;
            if (u->left)
                q.push(u->left);
            if (u->right)
                q.push(u->right);
        }
    }
    return sum;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    std::cout << deepestLeavesSum(root) << " (expected 15)\n";
    return 0;
}
