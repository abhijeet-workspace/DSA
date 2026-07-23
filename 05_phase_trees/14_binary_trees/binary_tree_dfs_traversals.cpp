// Binary Tree DFS Traversals — inorder / preorder / postorder
// Visit all nodes via recursion; order differs by when root is recorded.
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* node, std::vector<int>& res) {
    if (!node) {
        return;
    }
    inorder(node->left, res);   // left
    res.push_back(node->val);   // root
    inorder(node->right, res);  // right
}

void preorder(TreeNode* node, std::vector<int>& res) {
    if (!node) {
        return;
    }
    res.push_back(node->val);   // root
    preorder(node->left, res);  // left
    preorder(node->right, res); // right
}

void postorder(TreeNode* node, std::vector<int>& res) {
    if (!node) {
        return;
    }
    postorder(node->left, res);  // left
    postorder(node->right, res); // right
    res.push_back(node->val);    // root
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> res;
    inorder(root, res);
    return res;
}

std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> res;
    preorder(root, res);
    return res;
}

std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> res;
    postorder(root, res);
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    const auto in = inorderTraversal(root);
    const auto pre = preorderTraversal(root);
    const auto post = postorderTraversal(root);

    std::cout << "Inorder: ";
    for (int x : in) {
        std::cout << x << " ";
    }
    std::cout << "(expected 1 3 2)\n";

    std::cout << "Preorder: ";
    for (int x : pre) {
        std::cout << x << " ";
    }
    std::cout << "(expected 1 2 3)\n";

    std::cout << "Postorder: ";
    for (int x : post) {
        std::cout << x << " ";
    }
    std::cout << "(expected 3 2 1)\n";

    delete root->right->left;
    delete root->right;
    delete root;
    return 0;
}
