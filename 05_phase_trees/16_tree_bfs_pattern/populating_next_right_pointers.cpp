// Populating Next Right Pointers in Each Node —
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
#include <iostream>
#include <queue>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    explicit Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

Node* connect(Node* root) {
    if (!root)
        return root;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        Node* prev = nullptr;
        for (int i = 0; i < sz; ++i) {
            Node* u = q.front();
            q.pop();
            if (prev)
                prev->next = u;
            prev = u;
            if (u->left)
                q.push(u->left);
            if (u->right)
                q.push(u->right);
        }
    }
    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    connect(root);
    std::cout << (root->left->next == root->right ? "ok" : "bad") << "\n";
    std::cout << (root->left->left->next == root->left->right ? "ok" : "bad") << "\n";
    return 0;
}
