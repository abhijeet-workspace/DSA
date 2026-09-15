// Remove Duplicates from Sorted List II —
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Delete all nodes whose values appear more than once; return new head.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    while (prev->next) {
        ListNode* curr = prev->next;
        if (curr->next && curr->next->val == curr->val) {
            const int dup = curr->val;
            while (prev->next && prev->next->val == dup) {
                ListNode* doomed = prev->next;
                prev->next = doomed->next;
                delete doomed;
            }
        } else {
            prev = prev->next;
        }
    }
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
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    head = deleteDuplicates(head);
    std::cout << "result: ";
    printList(head); // expected 1 -> 2 -> 5
    while (head) {
        ListNode* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}
