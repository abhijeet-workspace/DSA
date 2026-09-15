// Merge Two Sorted Lists — LC 21 (recursive)
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
}

void printList(ListNode* h) {
    while (h) {
        std::cout << h->val;
        if (h->next)
            std::cout << "->";
        h = h->next;
    }
}

int main() {
    ListNode a1(1), a2(2), a3(4);
    a1.next = &a2;
    a2.next = &a3;
    ListNode b1(1), b2(3), b3(4);
    b1.next = &b2;
    b2.next = &b3;
    ListNode* m = mergeTwoLists(&a1, &b1);
    printList(m);
    std::cout << " (expected 1->1->2->3->4->4)\n";
    return 0;
}
