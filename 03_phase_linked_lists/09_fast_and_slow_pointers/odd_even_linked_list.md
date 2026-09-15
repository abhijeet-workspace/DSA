# Odd Even Linked List

## 1. Problem Statement
[LeetCode 328](https://leetcode.com/problems/odd-even-linked-list/) — group all odd-indexed nodes followed by even-indexed nodes (1-based indices). Relative order within each group must stay. O(1) space, O(N) time.

- **Inputs:** `ListNode* head`.
- **Output:** reordered head.
- **Valid answer:** odds then evens, stable within groups.
- **Edges:** empty; one/two nodes; odd/even length.

## 2. Intuition
Maintain two strands (`odd`, `even`) advancing in lockstep; splice even chain after the odd tail.

## 3. Brute Force → Optimal
- **Brute:** two vectors then reconnect — O(N) space.
- **Optimal:** two-pointer strand split — O(1) space.

## 4. Data Structure / Approach Justification
**Chosen:** odd/even pointer walk (same-direction dual pointers).

- **vs array collect:** violates O(1) space constraint.
- **vs value rearrange:** harder and unnecessary.

## 5. Logic Walkthrough
1. `odd = head`, `even = head->next`, save `evenHead`.
2. While `even` and `even->next`: `odd->next = even->next`; advance odd; `even->next = odd->next`; advance even.
3. `odd->next = evenHead`.

## 6. Dry Run
`1→2→3→4→5`: odds `1→3→5`, evens `2→4` → `1→3→5→2→4`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one pass, constant pointers (section 4).

## 8. Trade-offs & Alternatives
Collect-then-rebuild is simpler but uses O(N) memory.

## 9. Common Mistakes / Edge Cases
Confusing 0-based vs 1-based index; breaking even strand early; null on short lists.

## 10. Interview Follow-ups / Variations
Partition list by value; swap pairs; segregate even/odd values.

## 11. Tags
`linked-list`, `two-pointers`, `leetcode-328`, `difficulty:medium`
