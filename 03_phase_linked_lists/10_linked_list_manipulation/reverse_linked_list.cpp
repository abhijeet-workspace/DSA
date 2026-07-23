// Reverse Linked List — https://leetcode.com/problems/reverse-linked-list/
// Reverse a singly linked list; return the new head.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nxt = curr->next; // save rest
        curr->next = prev; // reverse edge
        prev = curr;
        curr = nxt;
    }
    return prev; // new head
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << "\n";
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode* reversed = reverseList(head);
    std::cout << "reversed: ";
    printList(reversed); // expected 3 -> 2 -> 1
    while (reversed) {
        ListNode* t = reversed;
        reversed = reversed->next;
        delete t;
    }
    return 0;
}
