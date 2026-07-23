// Binary Tree to DLL — GFG classic (inorder doubly linked list)
// Convert a binary tree into a DLL using left=prev, right=next; return DLL head.
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderLink(TreeNode* node, TreeNode*& prev, TreeNode*& head) {
    if (!node) {
        return;
    }
    inorderLink(node->left, prev, head); // left subtree first
    if (!prev) {
        head = node; // first inorder node is DLL head
    } else {
        prev->right = node; // prev -> next
        node->left = prev;  // node -> prev
    }
    prev = node; // advance prev
    inorderLink(node->right, prev, head); // then right subtree
}

TreeNode* binaryTreeToDll(TreeNode* root) {
    TreeNode* prev = nullptr;
    TreeNode* head = nullptr;
    inorderLink(root, prev, head);
    return head;
}

std::vector<int> dllForward(TreeNode* head) {
    std::vector<int> vals;
    for (TreeNode* cur = head; cur; cur = cur->right) {
        vals.push_back(cur->val);
    }
    return vals;
}

std::vector<int> dllBackward(TreeNode* head) {
    std::vector<int> vals;
    TreeNode* tail = head;
    while (tail && tail->right) {
        tail = tail->right;
    }
    for (TreeNode* cur = tail; cur; cur = cur->left) {
        vals.push_back(cur->val);
    }
    return vals;
}

int main() {
    /*
           4
          / \
         2   5
        / \
       1   3
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* head = binaryTreeToDll(root);
    const auto fwd = dllForward(head);
    const auto bwd = dllBackward(head);

    std::cout << "DLL forward: ";
    for (int x : fwd) {
        std::cout << x << " ";
    }
    std::cout << "(expected 1 2 3 4 5)\n";

    std::cout << "DLL backward: ";
    for (int x : bwd) {
        std::cout << x << " ";
    }
    std::cout << "(expected 5 4 3 2 1)\n";

    // nodes form one chain; delete from head
    while (head) {
        TreeNode* next = head->right;
        delete head;
        head = next;
    }
    return 0;
}
