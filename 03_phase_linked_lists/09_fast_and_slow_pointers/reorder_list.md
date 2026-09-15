# Reorder List

## 1. Problem Statement
[LeetCode 143](https://leetcode.com/problems/reorder-list/) — reorder `L0→L1→…→Ln` into `L0→Ln→L1→Ln-1→…` in place.

- **Inputs:** `ListNode* head`.
- **Output:** void (mutate list).
- **Valid answer:** alternating front and back nodes as specified.
- **Edges:** &lt;3 nodes (already done); even/odd length.

## 2. Intuition
Split at middle (slow/fast), reverse the second half, then weave the two halves.

## 3. Brute Force → Optimal
- **Brute:** store nodes in a deque/vector and rebuild — O(N) space.
- **Optimal:** mid + reverse + merge — O(1) space.

## 4. Data Structure / Approach Justification
**Chosen:** classic three-phase pointer surgery.

- **vs array:** simpler but uses O(N) memory.
- **vs recursion:** stack depth O(N).

## 5. Logic Walkthrough
1. Slow/fast to first mid; cut `slow->next`.
2. Reverse second half.
3. Alternate attach from half1 and half2.

## 6. Dry Run
`1→2→3→4→5`: cut after `3`; reverse `5→4`; weave → `1→5→2→4→3`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: three linear passes, constant pointers (section 4).

## 8. Trade-offs & Alternatives
Vector rebuild is safer under bugs; pointer weave is the expected answer.

## 9. Common Mistakes / Edge Cases
Wrong mid (leaving second mid attached); infinite loop if not cutting; losing next pointers while weaving.

## 10. Interview Follow-ups / Variations
Palindrome list (same mid+reverse); reverse in pairs; zig-zag reorder variants.

## 11. Tags
`linked-list`, `fast-slow-pointers`, `two-pointers`, `leetcode-143`, `difficulty:medium`
