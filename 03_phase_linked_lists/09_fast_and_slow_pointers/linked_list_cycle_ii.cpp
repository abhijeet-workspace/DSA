// Linked List Cycle II — https://leetcode.com/problems/linked-list-cycle-ii/
// Floyd: find meet, reset one to head, advance both → cycle start.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) {
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // meet inside cycle
            slow = head;    // reset one pointer to head
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next; // same speed → meet at entry
            }
            return slow;
        }
    }
    return nullptr; // acyclic
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // cycle at 2
    ListNode* entry = detectCycle(head);
    std::cout << (entry ? entry->val : -1) << " (expected 2)\n";
    head->next->next->next->next = nullptr; // break cycle
    entry = detectCycle(head);
    std::cout << (entry ? entry->val : -1) << " (expected -1)\n";
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
    return 0;
}
