// LC 2096 Step-By-Step Directions From a Binary Tree Node to Another
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
#include <iostream>
#include <string>
#include <vector>

struct Node {
    int val;
    Node *l, *r;
    Node(int v) : val(v), l(nullptr), r(nullptr) {}
};

bool pathTo(Node* u, int target, std::string& path) {
    if (!u)
        return false;
    if (u->val == target)
        return true;
    path.push_back('L');
    if (pathTo(u->l, target, path))
        return true;
    path.back() = 'R';
    if (pathTo(u->r, target, path))
        return true;
    path.pop_back();
    return false;
}

std::string getDirections(Node* root, int start, int dest) {
    std::string ps, pd;
    pathTo(root, start, ps);
    pathTo(root, dest, pd);
    size_t i = 0;
    while (i < ps.size() && i < pd.size() && ps[i] == pd[i])
        ++i;
    return std::string(ps.size() - i, 'U') + pd.substr(i);
}

int main() {
    // tree: 5 / \ 1 2 / \ / \ 3 n 6 4
    Node* root = new Node(5);
    root->l = new Node(1);
    root->r = new Node(2);
    root->l->l = new Node(3);
    root->r->l = new Node(6);
    root->r->r = new Node(4);
    std::string ans = getDirections(root, 3, 6);
    std::cout << "path=" << ans << " expected=UURL\n";
    bool ok = (ans == "UURL");
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
