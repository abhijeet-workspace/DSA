// LC 236 Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
#include <iostream>

struct Node {
    int val;
    Node *l, *r;
    Node(int v) : val(v), l(nullptr), r(nullptr) {}
};

Node* lca(Node* root, Node* p, Node* q) {
    if (!root || root == p || root == q)
        return root;
    Node* L = lca(root->l, p, q);
    Node* R = lca(root->r, p, q);
    if (L && R)
        return root;
    return L ? L : R;
}

int main() {
    Node* root = new Node(3);
    root->l = new Node(5);
    root->r = new Node(1);
    root->l->l = new Node(6);
    root->l->r = new Node(2);
    root->r->l = new Node(0);
    root->r->r = new Node(8);
    Node* ans = lca(root, root->l, root->r);
    std::cout << "lca=" << ans->val << " expected=3\n";
    bool ok = ans->val == 3;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
