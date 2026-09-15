// Next Greater Node In Linked List — https://leetcode.com/problems/next-greater-node-in-linked-list/
// For each node, value of the next strictly greater node to the right (0 if none).
#include <iostream>
#include <stack>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

std::vector<int> nextLargerNodes(ListNode* head) {
    std::vector<int> vals;
    for (ListNode* p = head; p != nullptr; p = p->next) {
        vals.push_back(p->val);
    }
    const int n = static_cast<int>(vals.size());
    std::vector<int> res(static_cast<size_t>(n), 0);
    std::stack<int> st; // indices, decreasing values
    for (int i = 0; i < n; ++i) {
        while (!st.empty() &&
               vals[static_cast<size_t>(st.top())] < vals[static_cast<size_t>(i)]) {
            res[static_cast<size_t>(st.top())] = vals[static_cast<size_t>(i)];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

ListNode* build(const std::vector<int>& a) {
    ListNode dummy(0);
    ListNode* t = &dummy;
    for (int x : a) {
        t->next = new ListNode(x);
        t = t->next;
    }
    return dummy.next;
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* n = head->next;
        delete head;
        head = n;
    }
}

int main() {
    ListNode* head = build({2, 1, 5});
    const auto res = nextLargerNodes(head);
    freeList(head);
    std::cout << "Next greater nodes:";
    for (int x : res) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 5 5 0)\n";
    return 0;
}
