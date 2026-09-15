// Intersection of Two Linked Lists — https://leetcode.com/problems/intersection-of-two-linked-lists/
// Return the shared node by reference, or nullptr.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) {
        return nullptr;
    }
    ListNode* pA = headA;
    ListNode* pB = headB;
    while (pA != pB) {
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }
    return pA;
}

int main() {
    ListNode* shared = new ListNode(8);
    shared->next = new ListNode(4);
    shared->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = shared;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = shared;

    ListNode* hit = getIntersectionNode(headA, headB);
    std::cout << (hit ? hit->val : -1) << " (expected 8)\n";

    // free unique prefixes + shared once
    delete headA->next;
    delete headA;
    delete headB->next->next;
    delete headB->next;
    delete headB;
    delete shared->next->next;
    delete shared->next;
    delete shared;
    return 0;
}
