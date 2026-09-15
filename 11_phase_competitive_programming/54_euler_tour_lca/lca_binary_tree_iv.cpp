// LC 1676 Lowest Common Ancestor of a Binary Tree IV
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/
#include <iostream>
#include <unordered_set>
#include <vector>

struct Node {
    int val;
    Node *l, *r;
    Node(int v) : val(v), l(nullptr), r(nullptr) {}
};

Node* lcaIV(Node* root, const std::unordered_set<int>& need) {
    if (!root)
        return nullptr;
    if (need.count(root->val))
        return root;
    Node* L = lcaIV(root->l, need);
    Node* R = lcaIV(root->r, need);
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
    std::unordered_set<int> need = {4, 7}; // not in tree — use 6 and 2 under 5
    need = {6, 2, 0};
    Node* ans = lcaIV(root, need);
    std::cout << "lca=" << ans->val << " expected=3\n";
    bool ok = ans && ans->val == 3;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
