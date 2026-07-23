# Reverse Linked List

## Problem Statement
[LeetCode 206](https://leetcode.com/problems/reverse-linked-list/) — reverse a singly linked list and return the new head.

- **Inputs:** `ListNode* head`.
- **Output:** head of reversed list.
- **Valid answer:** all edges flipped; original head becomes tail.
- **Edges:** empty; single node; two nodes.

## Intuition
Walk the list while redirecting each `next` to the previous node; keep `nxt` so the remainder is not lost.

## Brute Force → Optimal
- **Brute:** copy values to array, reverse, rewrite — O(N) space.
- **Optimal:** iterative three-pointer reverse — O(1) extra space.

## Data Structure / Approach Justification
**Chosen:** `prev` / `curr` / `nxt` iterative reverse.

- **vs recursion:** elegant but O(N) call stack.
- **vs new list prepend:** extra allocations if copying nodes.

## Logic Walkthrough
`prev=null`, `curr=head`. Loop: save `nxt`, set `curr->next=prev`, advance `prev=curr`, `curr=nxt`. Return `prev`.

## Dry Run
`1→2→3`: after steps, edges become `null←1←2←3`; return `3`.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: each node rewired once (section 4).

## Trade-offs & Alternatives
Recursive is shorter; iterative is production-safer for deep lists.

## Common Mistakes / Edge Cases
Losing `nxt` before rewiring; returning `curr` instead of `prev`; empty head.

## Interview Follow-ups / Variations
Reverse in k-groups (LC 25); reverse between left/right (LC 92); reverse doubly linked.

## Tags
`linked-list`, `reverse`, `two-pointers`, `difficulty:easy`
