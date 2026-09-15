# Merge Two Sorted Lists (Recursive)

## 1. Problem Statement
[LeetCode 21](https://leetcode.com/problems/merge-two-sorted-lists/) — Merge two sorted singly linked lists into one sorted list; return its head.

- **Inputs:** `ListNode* list1`, `ListNode* list2`.
- **Output:** Head of merged sorted list.
- **Edges:** One/both empty; all values from one list first.

## 2. Intuition
Pick the smaller head, recurse on the remainder, attach as `next`.

## 3. Brute Force → Optimal
Iterative two-pointer merge is standard. Recursion makes “choose head + merge rest” explicit.

## 4. Data Structure / Approach Justification
**Chosen:** recursive merge on `ListNode`.

Linked-list topics later own iterative merge, dummy heads, and pointer hygiene. **Focus here is recursion** on a list spine.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. If either list null, return the other.
2. Smaller head’s `next` = merge(rest, other); return that head.

## 6. Dry Run
`1→2→4` + `1→3→4` → pick 1, recurse → `1→1→2→3→4→4`.

## 7. Time & Space Complexity
- **Time:** O(n+m)
- **Space:** O(n+m) stack

## 8. Trade-offs & Alternatives
Iterative O(1) stack preferred in production/LL unit.

## 9. Common Mistakes / Edge Cases
Losing the non-chosen head; mutating wrong list; stack overflow on long lists.

## 10. Interview Follow-ups / Variations
Merge k lists; sort list via merge.

## 11. Tags
`recursion`, `linked-list`, `leetcode-21`, `difficulty:easy`
