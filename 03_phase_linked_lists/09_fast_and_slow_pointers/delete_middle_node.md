# Delete the Middle Node of a Linked List

## 1. Problem Statement
[LeetCode 2095](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) — delete the middle node of a singly linked list and return the head. For even length, delete the second of the two middle nodes. If only one node, return empty.

- **Inputs:** `ListNode* head`.
- **Output:** new head after deletion.
- **Valid answer:** list with middle bypassed (`n // 2` index, 0-based).
- **Edges:** single node; two nodes; odd/even length.

## 2. Intuition
Slow/fast finds the middle; keep a `prev` behind slow to unlink it.

## 3. Brute Force → Optimal
- **Brute:** count length, walk to index — two passes.
- **Optimal:** one-pass slow/fast with trailing `prev`.

## 4. Data Structure / Approach Justification
**Chosen:** fast/slow + predecessor pointer.

- **vs count:** extra pass.
- **vs array of nodes:** O(N) space.

## 5. Logic Walkthrough
1. If `head->next` is null, delete head and return null.
2. Advance slow/fast; track `prev = slow` each slow step.
3. When fast ends, `prev->next = slow->next`; delete `slow`.

## 6. Dry Run
`1→3→4→7→1→2→6`: slow lands on `7`; unlink → `1→3→4→1→2→6`.
`1→2→3→4`: middle index 2 → delete `3` → `1→2→4`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: single traversal (section 4).

## 8. Trade-offs & Alternatives
Two-pass is clearer; slow/fast matches middle-of-list pattern reuse.

## 9. Common Mistakes / Edge Cases
Deleting first middle on even length; forgetting single-node case; losing `prev`.

## 10. Interview Follow-ups / Variations
Return middle without delete (LC 876); remove nth from end.

## 11. Tags
`linked-list`, `fast-slow-pointers`, `leetcode-2095`, `difficulty:medium`
