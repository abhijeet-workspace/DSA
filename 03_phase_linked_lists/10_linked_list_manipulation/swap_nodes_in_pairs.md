# Swap Nodes in Pairs

## 1. Problem Statement
[LeetCode 24](https://leetcode.com/problems/swap-nodes-in-pairs/) — swap every two adjacent nodes in a singly linked list; return the new head.

- **Inputs:** `ListNode* head`.
- **Output:** head after pairwise swaps.
- **Valid answer:** pairs reversed; odd leftover node stays at end; nodes reused (values not just swapped if asked to swap nodes).
- **Edges:** empty; single node; odd length; exactly two nodes.

## 2. Intuition
Treat each pair as a local rewiring: `prev → a → b → rest` becomes `prev → b → a → rest`, then advance `prev` to `a`.

## 3. Brute Force → Optimal
- **Brute:** copy to array, swap indices, rebuild — O(N) space.
- **Optimal:** dummy + iterative pair splice — O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** dummy node and pointer `prev` before each pair.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Recursion on pairs | O(N/2) stack |
| Swap values only | Wrong if problem requires node objects swapped |

## 5. Logic Walkthrough
1. `dummy.next = head`, `prev = &dummy`.
2. While `prev->next` and `prev->next->next` exist: let `a`,`b` be the pair; rewire `a→rest`, `b→a`, `prev→b`; set `prev = a`.
3. Return `dummy.next`.

## 6. Dry Run
`1→2→3→4`: first pair → `2→1→3→4`; second → `2→1→4→3`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Recursive version is shorter; iterative is safer for long lists and mirrors k-group (LC 25) with `k=2`.

## 9. Common Mistakes / Edge Cases
Losing `rest` before rewiring; advancing `prev` to `b` instead of `a`; odd-length leftover.

## 10. Interview Follow-ups / Variations
Reverse k-group (LC 25); swap only odd-indexed pairs; reverse between bounds (LC 92).

## 11. Tags
`linked-list`, `swap`, `dummy-node`, `leetcode-24`, `difficulty:medium`
