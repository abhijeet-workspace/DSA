// Reverse Linked List — LC 206 (recursive)
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

void printList(ListNode* h) {
    while (h) {
        std::cout << h->val;
        if (h->next) std::cout << "->";
        h = h->next;
    }
}

int main() {
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;
    ListNode* r = reverseList(&n1);
    printList(r);
    std::cout << " (expected 5->4->3->2->1)\n";
    return 0;
}
