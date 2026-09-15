// Rotate List — https://leetcode.com/problems/rotate-list/
// Rotate right by k; return new head.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
        return head;
    }
    int n = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        ++n;
    }
    k %= n;
    if (k == 0) {
        return head;
    }
    tail->next = head; // circularize
    int steps = n - k;
    ListNode* newTail = head;
    for (int i = 1; i < steps; ++i) {
        newTail = newTail->next;
    }
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
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
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = rotateRight(head, 2);
    std::cout << "result: ";
    printList(head); // expected 4 -> 5 -> 1 -> 2 -> 3
    while (head) {
        ListNode* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}
