// Clone Graph — https://leetcode.com/problems/clone-graph/
// Deep-copy a connected undirected graph; return the clone of the given node.
#include <iostream>
#include <unordered_map>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    explicit Node(int v) : val(v) {}
};

Node* cloneGraph(Node* node, std::unordered_map<Node*, Node*>& seen) {
    if (!node) {
        return nullptr;
    }
    if (seen.count(node)) {
        return seen[node]; // already cloned
    }
    Node* copy = new Node(node->val);
    seen[node] = copy; // memo before recursion (cycles)
    for (Node* nb : node->neighbors) {
        copy->neighbors.push_back(cloneGraph(nb, seen));
    }
    return copy;
}

Node* cloneGraph(Node* node) {
    std::unordered_map<Node*, Node*> seen;
    return cloneGraph(node, seen);
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Node* cloned = cloneGraph(n1);
    std::cout << "head=" << cloned->val << " neighbors=";
    for (Node* n : cloned->neighbors) {
        std::cout << n->val << " ";
    }
    std::cout << "(expected 2 4)\n";
    return 0;
}
