# Odd Even Linked List

## 1. Problem Statement
[LeetCode 328](https://leetcode.com/problems/odd-even-linked-list/) — rearrange a singly linked list so all odd-indexed nodes come before even-indexed nodes (1-based index); preserve relative order within each group.

- **Inputs:** `ListNode* head`.
- **Output:** new head (often same as original head).
- **Valid answer:** odds then evens by original positions, not by node values.
- **Edges:** empty; one/two nodes; odd vs even length.

## 2. Intuition
Maintain two chains in one pass: weave odds forward and evens forward, then splice `oddTail → evenHead`.

## 3. Brute Force → Optimal
- **Brute:** collect odd then even pointers into a vector and relink — O(N) space.
- **Optimal:** in-place dual pointers — O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** `odd` / `even` / `evenHead` while `even` and `even->next` exist.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Value-based odd/even | Wrong problem statement |
| Two dummy lists then merge | Extra allocations / clearer but not required |

## 5. Logic Walkthrough
1. `odd = head`, `even = head->next`, save `evenHead`.
2. Loop: `odd->next = even->next`, advance `odd`; `even->next = odd->next`, advance `even`.
3. `odd->next = evenHead`; return `head`.

## 6. Dry Run
`1→2→3→4→5`: odds `1→3→5`, evens `2→4` → `1→3→5→2→4`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Dummy odd/even lists are easier to reason about under pressure; same asymptotics.

## 9. Common Mistakes / Edge Cases
Confusing value parity with index parity; null-deref when advancing; forgetting to attach `evenHead`.

## 10. Interview Follow-ups / Variations
Partition by value (LC 86); segregate 0/1; reverse odds only.

## 11. Tags
`linked-list`, `two-pointers`, `reorder`, `leetcode-328`, `difficulty:medium`
