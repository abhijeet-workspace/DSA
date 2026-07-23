// Merge Two Sorted Lists — https://leetcode.com/problems/merge-two-sorted-lists/
// Merge two sorted lists into one sorted list; reuse nodes.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (list1 && list2) { // both still have nodes
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next; // advance merge tip
    }
    tail->next = list1 ? list1 : list2; // attach remainder
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
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);
    ListNode* merged = mergeTwoLists(l1, l2);
    std::cout << "merged: ";
    printList(merged); // expected 1 -> 2 -> 3 -> 4 -> 5 -> 6
    while (merged) {
        ListNode* t = merged;
        merged = merged->next;
        delete t;
    }
    return 0;
}
