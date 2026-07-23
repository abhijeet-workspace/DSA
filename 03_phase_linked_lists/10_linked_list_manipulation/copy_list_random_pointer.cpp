// Copy List with Random Pointer — https://leetcode.com/problems/copy-list-with-random-pointer/
// Deep-copy a list where each node also has a random pointer.
#include <iostream>

struct Node {
    int val;
    Node* next;
    Node* random;
    explicit Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) {
        return nullptr;
    }
    Node* curr = head;
    while (curr) { // weave copy after each original
        Node* copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    curr = head;
    while (curr) { // set copy random via original->random->next
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    curr = head;
    Node dummy(0);
    Node* copyCurr = &dummy;
    while (curr) { // unweave into original + copy
        copyCurr->next = curr->next;
        copyCurr = copyCurr->next;
        curr->next = curr->next->next;
        curr = curr->next;
    }
    return dummy.next;
}

int main() {
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    n1->next = n2;
    n2->next = n3;
    n1->random = nullptr;
    n2->random = n1;
    n3->random = n2;
    Node* copyHead = copyRandomList(n1);
    std::cout << "copy: " << copyHead->val << ", "
              << copyHead->next->val << " random="
              << copyHead->next->random->val << ", "
              << copyHead->next->next->val << " random="
              << copyHead->next->next->random->val
              << " (expected 7, 13 random=7, 11 random=13)\n";
    while (n1) {
        Node* t = n1;
        n1 = n1->next;
        delete t;
    }
    while (copyHead) {
        Node* t = copyHead;
        copyHead = copyHead->next;
        delete t;
    }
    return 0;
}
