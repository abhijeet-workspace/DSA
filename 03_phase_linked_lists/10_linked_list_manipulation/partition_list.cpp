// Partition List — https://leetcode.com/problems/partition-list/
// Stable-partition nodes: values < x before values >= x; preserve relative order.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode lessDummy(0);
    ListNode geDummy(0);
    ListNode* less = &lessDummy;
    ListNode* ge = &geDummy;
    for (ListNode* curr = head; curr; curr = curr->next) {
        if (curr->val < x) {
            less->next = curr;
            less = less->next;
        } else {
            ge->next = curr;
            ge = ge->next;
        }
    }
    ge->next = nullptr;        // terminate >= chain
    less->next = geDummy.next; // join
    return lessDummy.next;
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
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    ListNode* res = partition(head, 3);
    std::cout << "partition x=3: ";
    printList(res); // expected 1 -> 2 -> 2 -> 4 -> 3 -> 5
    while (res) {
        ListNode* t = res;
        res = res->next;
        delete t;
    }
    return 0;
}
