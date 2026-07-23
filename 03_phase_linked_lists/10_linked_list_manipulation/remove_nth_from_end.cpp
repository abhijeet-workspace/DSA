// Remove Nth Node From End — https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Remove the nth node from the end; return the new head.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* first = &dummy;
    ListNode* second = &dummy;
    for (int i = 0; i <= n; ++i) { // first leads by n+1 from dummy
        first = first->next;
    }
    while (first) { // move together to end
        first = first->next;
        second = second->next;
    }
    ListNode* toDelete = second->next;
    second->next = second->next->next; // bypass
    delete toDelete;
    return dummy.next;
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
    head = removeNthFromEnd(head, 2);
    std::cout << "result: ";
    printList(head); // expected 1 -> 2 -> 3 -> 5
    while (head) {
        ListNode* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}
