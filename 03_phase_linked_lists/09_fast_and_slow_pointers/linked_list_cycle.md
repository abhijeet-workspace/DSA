# Linked List Cycle

## Problem Statement
[LeetCode 141](https://leetcode.com/problems/linked-list-cycle/) — return whether a singly linked list has a cycle.

- **Inputs:** `ListNode* head`.
- **Output:** `bool`.
- **Valid answer:** `true` iff some node is reachable again by following `next`.
- **Edges:** empty; one node; cycle at head; long tail then cycle.

## Intuition
If a cycle exists, a pointer moving twice as fast will lap the slow one inside the loop (Floyd).

## Brute Force → Optimal
- **Brute:** hash visited node addresses — O(N) time, O(N) space.
- **Optimal:** tortoise/hare — O(N) time, O(1) space.

## Data Structure / Approach Justification
**Chosen:** two pointers at relative speed 1; no extra storage.

- **vs hash set:** correct but wastes memory interviews usually disallow.
- **vs mutating nodes (mark visited):** destroys input / needs restore.

## Logic Walkthrough
Advance `slow` by 1 and `fast` by 2 while `fast` and `fast->next` exist. If pointers equal, cycle. If `fast` hits null, no cycle.

## Dry Run
`1→2→3→4→2…`: after several steps `slow` and `fast` land on the same node inside `{2,3,4}` → `true`. Break the back edge → `fast` reaches null → `false`.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: at most a constant number of laps before meet or exit (section 4).

## Trade-offs & Alternatives
Hash is simpler under time pressure; Floyd is the expected O(1)-space answer.

## Common Mistakes / Edge Cases
Advancing `fast->next->next` without null-checking `fast->next`; empty list; self-loop.

## Interview Follow-ups / Variations
Find cycle entry (LC 142); compute cycle length; happy-number analogy.

## Tags
`linked-list`, `fast-slow-pointers`, `floyd`, `difficulty:easy`
