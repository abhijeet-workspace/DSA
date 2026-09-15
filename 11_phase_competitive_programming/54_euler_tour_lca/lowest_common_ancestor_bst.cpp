// LC 235 Lowest Common Ancestor of a BST
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include <iostream>

struct Node {
    int val;
    Node *l, *r;
    Node(int v) : val(v), l(nullptr), r(nullptr) {}
};

Node* lca(Node* root, Node* p, Node* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val)
            root = root->l;
        else if (p->val > root->val && q->val > root->val)
            root = root->r;
        else
            return root;
    }
    return nullptr;
}

int main() {
    Node* root = new Node(6);
    root->l = new Node(2);
    root->r = new Node(8);
    root->l->l = new Node(0);
    root->l->r = new Node(4);
    Node* ans = lca(root, root->l, root->r);
    std::cout << "lca=" << ans->val << " expected=6\n";
    bool ok = ans->val == 6;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
