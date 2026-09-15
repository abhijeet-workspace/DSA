# Swap Nodes in Pairs

## 1. Problem Statement
[LeetCode 24](https://leetcode.com/problems/swap-nodes-in-pairs/) — swap every two adjacent nodes in a linked list and return its head. Swap nodes, not values.

- **Inputs:** `ListNode* head`.
- **Output:** new head after pairwise swaps.
- **Valid answer:** pairs swapped; odd trailing node unchanged.
- **Edges:** empty; one node; odd length; even length.

## 2. Intuition
Walk with a dummy predecessor; for each pair, rewire `prev→b→a→rest`, then advance.

## 3. Brute Force → Optimal
- **Brute:** copy to array, swap indices, rebuild — O(N) space.
- **Optimal:** iterative pointer rewiring — O(1) space.

## 4. Data Structure / Approach Justification
**Chosen:** dummy + local two-node swap loop (weaker fast/slow cousin: fixed stride-2).

- **vs value swap:** violates “swap nodes” constraint.
- **vs recursion:** elegant but O(N) stack.

## 5. Logic Walkthrough
While `prev->next` and `prev->next->next` exist: let `a`, `b` be the pair; set `prev->next = b`, `a->next = b->next`, `b->next = a`; `prev = a`.

## 6. Dry Run
`1→2→3→4`: first swap → `2→1→3→4`; then → `2→1→4→3`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one pass, constant pointers (section 4).

## 8. Trade-offs & Alternatives
Recursion is shorter; iterative is safer for long lists.

## 9. Common Mistakes / Edge Cases
Losing the rest of the list; swapping values; forgetting dummy for new head.

## 10. Interview Follow-ups / Variations
Reverse nodes in k-group; odd-even list; rotate list.

## 11. Tags
`linked-list`, `two-pointers`, `leetcode-24`, `difficulty:medium`
