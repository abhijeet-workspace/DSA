# Minimum Swaps To Make Sequences Increasing

## 1. Problem Statement
[LeetCode 801](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/) — two arrays `A`, `B`; at index `i` you may swap `A[i]` with `B[i]`. Minimize swaps so both become strictly increasing.

- **Inputs:** equal-length arrays.
- **Output:** minimum swaps.
- **Edges:** already increasing; must swap at boundaries.

## 2. Intuition
DP states at `i`: last index swapped or not; transitions when local inequalities hold (dependency like a path DAG of positions).

## 3. Brute Force → Optimal
- **Brute:** 2^N swap masks.
- **Optimal:** O(N) two-state DP.

## 4. Data Structure / Approach Justification
**Chosen:** rolling `keep`/`swap` DP along indices (topo order of positions).

| Alternative | Note |
|-------------|------|
| Explicit graph of states | Same idea, heavier |

## 5. Logic Walkthrough
From previous keep/swap, try continuing without/with swap when both sequences stay increasing.

## 6. Dry Run
`A=[1,3,5,4], B=[1,2,3,7]` → `1` swap.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**.

## 8. Trade-offs & Alternatives
Framed here as linear DAG DP over positions.

## 9. Common Mistakes / Edge Cases
Allowing equal (not strict); mixing A/B comparisons.

## 10. Interview Follow-ups / Variations
At most one array must increase; three arrays.

## 11. Tags
`leetcode-801`, `dp`, `topological-framing`, `difficulty:hard`
