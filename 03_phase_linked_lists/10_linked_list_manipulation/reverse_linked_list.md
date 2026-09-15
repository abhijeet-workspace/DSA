# Reverse Linked List

## 1. Problem Statement
[LeetCode 206](https://leetcode.com/problems/reverse-linked-list/) — reverse a singly linked list and return the new head.

- **Inputs:** `ListNode* head`.
- **Output:** head of reversed list.
- **Valid answer:** all edges flipped; original head becomes tail.
- **Edges:** empty; single node; two nodes.

## 2. Intuition
Walk the list while redirecting each `next` to the previous node; keep `nxt` so the remainder is not lost.

## 3. Brute Force → Optimal
- **Brute:** copy values to array, reverse, rewrite — O(N) space.
- **Optimal:** iterative three-pointer reverse — O(1) extra space.

## 4. Data Structure / Approach Justification
**Chosen:** `prev` / `curr` / `nxt` iterative reverse.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Recursion | Elegant but O(N) call stack |
| New list prepend | Extra allocations if copying nodes |

## 5. Logic Walkthrough
1. `prev = null`, `curr = head`.
2. Loop: save `nxt`, set `curr->next = prev`, advance `prev = curr`, `curr = nxt`.
3. Return `prev`.

## 6. Dry Run
`1→2→3`: after steps, edges become `null←1←2←3`; return `3`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Recursive is shorter; iterative is production-safer for deep lists.

## 9. Common Mistakes / Edge Cases
Losing `nxt` before rewiring; returning `curr` instead of `prev`; empty head.

## 10. Interview Follow-ups / Variations
Reverse in k-groups (LC 25); reverse between left/right (LC 92); reverse doubly linked.

## 11. Tags
`linked-list`, `reverse`, `two-pointers`, `leetcode-206`, `difficulty:easy`
