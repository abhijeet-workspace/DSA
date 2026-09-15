// Even Odd Tree — https://leetcode.com/problems/even-odd-tree/
#include <climits>
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isEvenOddTree(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;
        for (int i = 0; i < sz; ++i) {
            TreeNode* u = q.front();
            q.pop();
            if (level % 2 == 0) {
                if (u->val % 2 == 0 || u->val <= prev)
                    return false;
            } else {
                if (u->val % 2 != 0 || u->val >= prev)
                    return false;
            }
            prev = u->val;
            if (u->left)
                q.push(u->left);
            if (u->right)
                q.push(u->right);
        }
        ++level;
    }
    return true;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(8);
    root->right->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(2);
    std::cout << std::boolalpha << isEvenOddTree(root) << " (expected true)\n";
    return 0;
}
