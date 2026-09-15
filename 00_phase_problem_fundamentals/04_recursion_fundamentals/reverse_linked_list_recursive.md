# Reverse Linked List (Recursive)

## 1. Problem Statement
[LeetCode 206](https://leetcode.com/problems/reverse-linked-list/) — Reverse a singly linked list; return the new head.

- **Inputs:** `ListNode* head`.
- **Output:** New head.
- **Edges:** Empty; single node; two nodes.

## 2. Intuition
Reverse the tail first; then make the old head the new tail via `head->next->next = head`.

## 3. Brute Force → Optimal
Iterative prev/cur/next is the LL-unit default. Recursion shows post-order pointer flip.

## 4. Data Structure / Approach Justification
**Chosen:** recursive reverse on `ListNode`.

Same pedagogy as merge: LL topics later; **here the lesson is the call stack + post-order rewrite**.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. Base: null or single node → return head.
2. `newHead = reverse(head->next)`.
3. `head->next->next = head`; `head->next = null`; return `newHead`.

## 6. Dry Run
`1→2→3`: reverse tail → `3→2`, then attach 1 → `3→2→1`.

## 7. Time & Space Complexity
- **Time:** O(n)
- **Space:** O(n) stack

## 8. Trade-offs & Alternatives
Iterative O(1) space preferred for long lists.

## 9. Common Mistakes / Edge Cases
Forgetting to null old head’s next (cycle); returning wrong head.

## 10. Interview Follow-ups / Variations
Reverse between m..n; reverse k-group.

## 11. Tags
`recursion`, `linked-list`, `leetcode-206`, `difficulty:easy`
