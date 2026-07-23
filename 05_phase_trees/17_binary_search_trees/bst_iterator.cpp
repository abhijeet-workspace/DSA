// BST Iterator — https://leetcode.com/problems/binary-search-tree-iterator/
// In-order iterator with next()/hasNext(); stack holds path of pending lefts.
#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
    std::stack<TreeNode*> s;

    void pushAllLeft(TreeNode* node) {
        while (node) {
            s.push(node);
            node = node->left; // descend left spine
        }
    }

public:
    explicit BSTIterator(TreeNode* root) { pushAllLeft(root); }

    int next() {
        TreeNode* curr = s.top();
        s.pop();
        if (curr->right) {
            pushAllLeft(curr->right); // next inorder after curr
        }
        return curr->val;
    }

    bool hasNext() const { return !s.empty(); }
};

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);
    std::cout << "In-order: ";
    while (it.hasNext()) {
        std::cout << it.next() << " ";
    }
    std::cout << "(expected 3 7 9 15 20)\n";
    return 0;
}
