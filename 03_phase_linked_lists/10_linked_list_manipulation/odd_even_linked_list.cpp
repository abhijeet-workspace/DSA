// Odd Even Linked List — https://leetcode.com/problems/odd-even-linked-list/
// Group odd-indexed nodes then even-indexed; preserve relative order in each group.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead; // append even chain
    return head;
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
    ListNode* res = oddEvenList(head);
    std::cout << "odd-even: ";
    printList(res); // expected 1 -> 3 -> 5 -> 2 -> 4
    while (res) {
        ListNode* t = res;
        res = res->next;
        delete t;
    }
    return 0;
}
