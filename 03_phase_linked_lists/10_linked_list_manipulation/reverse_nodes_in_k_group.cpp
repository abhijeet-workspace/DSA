// Reverse Nodes in k-Group — https://leetcode.com/problems/reverse-nodes-in-k-group/
// Reverse the list in groups of k nodes; leave a trailing short group as-is.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) {
        return head;
    }
    int count = 0;
    for (ListNode* p = head; p; p = p->next) { // total length
        ++count;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prevGroup = &dummy;
    ListNode* currGroup = head;
    while (count >= k) { // only full groups
        ListNode* curr = currGroup;
        ListNode* prev = nullptr;
        for (int i = 0; i < k; ++i) { // reverse k nodes
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        ListNode* groupTail = prevGroup->next; // old head becomes tail
        prevGroup->next = prev; // new group head
        groupTail->next = curr; // link to remainder
        prevGroup = groupTail;
        currGroup = curr;
        count -= k;
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
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* res = reverseKGroup(head, 2);
    std::cout << "k=2: ";
    printList(res); // expected 2 -> 1 -> 4 -> 3 -> 5
    while (res) {
        ListNode* t = res;
        res = res->next;
        delete t;
    }
    return 0;
}
