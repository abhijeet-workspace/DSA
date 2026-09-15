# Minimum Operations to Halve Array Sum

## 1. Problem Statement
[LeetCode 2208](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/) — operation: choose index and replace `nums[i]` with `nums[i]/2`; return min ops so sum ≤ half of original sum.

- **Inputs:** `nums` positive integers.
- **Output:** minimum operations.
- **Valid answer:** always halve current largest.
- **Edges:** one element; already tiny; need many ops on same value.

## 2. Intuition
Halving the largest residual contributes most toward the reduction target — max-heap of floats.

## 3. Brute Force → Optimal
- **Brute:** search sequences — impossible at scale.
- **Optimal:** max-heap until reduced ≥ sum/2.

## 4. Data Structure / Approach Justification
**Chosen:** `priority_queue<double>`.

- **Adjacent single-heap** in two-heaps folder for comparison with dual-PQ problems.

## 5. Logic Walkthrough
Compute sum/2 target. While reduced < target: pop max, add half to reduced, push half back.

## 6. Dry Run
`[5,19,8,1]` → ops **3**.

## 7. Time & Space Complexity
Time **O(N + Ops log N)**. Space **O(N)**. Why: each op is a heap replace (section 4).

## 8. Trade-offs & Alternatives
Floating error is fine under LC constraints; can use integers with fixed-point if desired.

## 9. Common Mistakes / Edge Cases
Stopping at sum < target incorrectly; using min-heap; integer-only halves losing precision mid-way.

## 10. Interview Follow-ups / Variations
Remove Stones (1962); Maximal Score After K Operations.

## 11. Tags
`heap`, `greedy`, `leetcode-2208`, `difficulty:medium`
