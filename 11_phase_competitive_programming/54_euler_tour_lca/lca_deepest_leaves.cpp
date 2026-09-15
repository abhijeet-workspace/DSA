// LC 1123 Lowest Common Ancestor of Deepest Leaves
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
#include <iostream>
#include <utility>

struct Node {
    int val;
    Node *l, *r;
    Node(int v) : val(v), l(nullptr), r(nullptr) {}
};

std::pair<Node*, int> dfs(Node* u) {
    if (!u)
        return {nullptr, 0};
    auto L = dfs(u->l), R = dfs(u->r);
    if (L.second > R.second)
        return {L.first, L.second + 1};
    if (R.second > L.second)
        return {R.first, R.second + 1};
    return {u, L.second + 1};
}

int main() {
    Node* root = new Node(3);
    root->l = new Node(5);
    root->r = new Node(1);
    root->l->l = new Node(6);
    root->l->r = new Node(2);
    root->l->r->l = new Node(7);
    root->l->r->r = new Node(4);
    root->r->l = new Node(0);
    root->r->r = new Node(8);
    auto ans = dfs(root).first;
    std::cout << "lca=" << ans->val << " expected=2\n";
    bool ok = ans->val == 2;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
