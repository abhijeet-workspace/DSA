# Reorder List

## 1. Problem Statement
[LeetCode 143](https://leetcode.com/problems/reorder-list/) — reorder `L0→L1→…→Ln` in-place to `L0→Ln→L1→Ln-1→…`.

- **Inputs:** `ListNode* head`.
- **Output:** void; list mutated in place.
- **Valid answer:** alternating from start and end using original nodes.
- **Edges:** `<3` nodes (no-op); even vs odd length.

## 2. Intuition
Split at middle, reverse the second half, then weave the two halves node by node.

## 3. Brute Force → Optimal
- **Brute:** store nodes in a vector and rebuild indices — O(N) space.
- **Optimal:** mid + reverse + merge — O(1) extra space.

## 4. Data Structure / Approach Justification
**Chosen:** slow/fast split, iterative reverse, two-pointer weave.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Vector of pointers | Simpler coding, uses O(N) memory |
| Recursion | O(N) stack; harder to control mid cut |

## 5. Logic Walkthrough
1. Find mid (`slow`); cut `slow->next = null`.
2. Reverse second half into `prev`.
3. While `p2` remains, insert `p2` after `p1` and advance both.

## 6. Dry Run
`1→2→3→4→5`: halves `1→2→3` and `4→5`; reverse → `5→4`; weave → `1→5→2→4→3`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Vector approach is faster to implement under pressure; in-place is expected for senior interviews.

## 9. Common Mistakes / Edge Cases
Not cutting mid (creates a cycle); wrong mid for even length; weaving past null.

## 10. Interview Follow-ups / Variations
Reorder by k groups; palindrome check shares mid+reverse; reverse between bounds.

## 11. Tags
`linked-list`, `two-pointers`, `reverse`, `reorder`, `leetcode-143`, `difficulty:medium`
