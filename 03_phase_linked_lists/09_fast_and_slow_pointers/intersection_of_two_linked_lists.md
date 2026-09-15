# Intersection of Two Linked Lists

## 1. Problem Statement
[LeetCode 160](https://leetcode.com/problems/intersection-of-two-linked-lists/) — return the node at which two singly linked lists intersect, or `nullptr` if they do not. By reference equality, not value.

- **Inputs:** `ListNode* headA`, `ListNode* headB`.
- **Output:** intersection node or null.
- **Valid answer:** first shared node object (same address).
- **Edges:** no intersection; intersect at head; different lengths; one empty.

## 2. Intuition
Two pointers traverse A then B (and vice versa). Equal total path length forces a meet at the intersection (or both null).

## 3. Brute Force → Optimal
- **Brute:** hash nodes of A, scan B — O(N) space.
- **Optimal:** dual traversal switch — O(1) space.

## 4. Data Structure / Approach Justification
**Chosen:** two pointers with list switch (length-gap cancellation).

- **vs length align then walk:** also O(1) space; switch trick avoids explicit counts.
- **vs hash:** uses memory.

## 5. Logic Walkthrough
`pA = headA`, `pB = headB`. While unequal: advance each; if null, jump to the other list’s head. Return `pA` (may be null).

## 6. Dry Run
A: `4→1→8→4→5`, B: `5→6→1→8→4→5` share from `8`. After A finishes and jumps to B (and B to A), pointers meet at `8`.

## 7. Time & Space Complexity
Time **O(N + M)**. Space **O(1)**. Why: each pointer walks at most both lists once (section 4).

## 8. Trade-offs & Alternatives
Count-and-align is more obvious; switch method is elegant and common in interviews.

## 9. Common Mistakes / Edge Cases
Comparing values instead of pointers; infinite loop if not switching to null correctly; assuming values uniquely identify nodes.

## 10. Interview Follow-ups / Variations
Detect cycle (same-node meet idea); find merge point of Y-shaped lists with cycles.

## 11. Tags
`linked-list`, `two-pointers`, `leetcode-160`, `difficulty:easy`
