// Add Two Numbers — https://leetcode.com/problems/add-two-numbers/
// Digits in reverse-order lists; return sum as a linked list.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) { // continue while digits or carry remain
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10; // next carry
        curr->next = new ListNode(sum % 10); // write digit
        curr = curr->next;
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
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3); // 342
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4); // 465
    ListNode* sum = addTwoNumbers(l1, l2);
    std::cout << "sum: ";
    printList(sum); // expected 7 -> 0 -> 8
    while (l1) {
        ListNode* t = l1;
        l1 = l1->next;
        delete t;
    }
    while (l2) {
        ListNode* t = l2;
        l2 = l2->next;
        delete t;
    }
    while (sum) {
        ListNode* t = sum;
        sum = sum->next;
        delete t;
    }
    return 0;
}
