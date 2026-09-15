# Linked List Cycle II

## Problem Statement
[LeetCode 142](https://leetcode.com/problems/linked-list-cycle-ii/) — return the node where the cycle begins, or `nullptr` if acyclic.

- **Inputs:** `ListNode* head`.
- **Output:** `ListNode*` cycle entry (or null).
- **Valid answer:** first node reachable twice by following `next`.
- **Edges:** empty; no cycle; cycle at head; self-loop; long tail then cycle.

## Intuition
Floyd: after tortoise/hare meet inside the cycle, the distance from head to entry equals the distance from meet to entry (mod cycle length). Reset one pointer to head and walk both at speed 1.

## Brute Force → Optimal
- **Brute:** hash visited addresses — O(N) time, O(N) space.
- **Optimal:** Floyd two-phase — O(N) time, O(1) space.

## Data Structure / Approach Justification
**Chosen:** Floyd meet + reset walk.

- **vs hash set:** correct but uses O(N) memory.
- **vs mutating / marking nodes:** destroys input.

## Logic Walkthrough
Phase 1: `slow` +1, `fast` +2 until equal (or null → no cycle). Phase 2: set `slow = head`; advance both +1 until equal — that node is the entry.

## Dry Run
`3→2→0→-4→2…`: meet somewhere in `{2,0,-4}`; reset `slow` to 3; both meet at `2` → entry.

Break back edge → phase 1 hits null → `nullptr`.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: constant number of passes over the list (section 4).

## Trade-offs & Alternatives
Hash is simpler under time pressure; Floyd is the expected O(1)-space answer and unlocks cycle-length follow-ups.

## Common Mistakes / Edge Cases
Returning the meet node instead of resetting; forgetting null checks on `fast->next`; cycle at head.

## Interview Follow-ups / Variations
Cycle length; happy number; copy list with random pointer (hash); remove cycle.

## Tags
`linked-list`, `fast-slow-pointers`, `floyd`, `leetcode-142`, `difficulty:medium`
