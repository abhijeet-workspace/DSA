# Merge Two Sorted Lists

## Problem Statement
[LeetCode 21](https://leetcode.com/problems/merge-two-sorted-lists/) — merge two sorted singly linked lists into one sorted list by reusing existing nodes.

- **Inputs:** `list1`, `list2` (sorted non-decreasing).
- **Output:** head of merged sorted list.
- **Valid answer:** all nodes from both lists in sorted order.
- **Edges:** one/both empty; one exhausted early; duplicates.

## Intuition
Same as mergesort merge: always take the smaller current head; splice the leftover chain at the end.

## Brute Force → Optimal
- **Brute:** collect values, sort, rebuild — O((N+M) log(N+M)).
- **Optimal:** dummy + two-pointer splice — O(N+M), O(1) extra.

## Data Structure / Approach Justification
**Chosen:** iterative dummy head / `tail` pointer.

- **vs recursion:** elegant but O(N+M) stack.
- **vs rebuild values:** wastes time and allocations.

## Logic Walkthrough
While both non-null, attach the smaller node to `tail` and advance that list. After loop, `tail->next` gets whichever list remains. Return `dummy.next`.

## Dry Run
`1→3→5` and `2→4→6`: pick 1,2,3,4,5 then attach 6 → `1→2→3→4→5→6`.

## Time & Space Complexity
Time **O(N+M)**. Space **O(1)** extra. Why: each node visited once; only pointers move (section 4).

## Trade-offs & Alternatives
Recursive is shorter to write; iterative is safer for long lists.

## Common Mistakes / Edge Cases
Forgetting to link the remaining list; losing a node by advancing before linking; null inputs.

## Interview Follow-ups / Variations
Merge K lists (LC 23); sort a list via mergesort; merge in reverse order.

## Tags
`linked-list`, `two-pointers`, `merge`, `dummy-node`, `difficulty:easy`
