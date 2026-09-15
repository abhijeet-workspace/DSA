# Combination Sum III

## 1. Problem Statement
[LeetCode 216](https://leetcode.com/problems/combination-sum-iii/) — find all valid combinations of `k` distinct integers in `[1,9]` that sum to `n`. Each number used at most once.

- **Inputs:** `int k`, `int n`.
- **Output:** list of combinations (any order).
- **Valid answer:** each combo has length `k`, distinct digits 1–9, sum `n`.
- **Edges:** impossible `k`/`n`; `k=1`; max sum `45`.

## 2. Intuition
Cascade from `start..9`: pick `x`, then recurse with `k-1` and `n-x` starting at `x+1` (no reuse, no permutations).

## 3. Brute Force → Optimal
- **Brute:** all C(9,k) then filter by sum — fine for n≤9.
- **Optimal:** same search with early prune when `x > remain`.

## 4. Data Structure / Approach Justification
**Chosen:** for-loop DFS with remaining `k` and `remain`.

- **vs include/exclude on 1..9:** equivalent; for-loop matches combinations template.
- **vs DP:** overkill for tiny domain.

## 5. Logic Walkthrough
Base: `k==0 && remain==0` → record. Else try `x` from `start` to 9 with prune; push, recurse `x+1`, pop.

## 6. Dry Run
`k=3`, `n=7` → only `[1,2,4]`.

## 7. Time & Space Complexity
Time **O(C(9,k))** worst. Space **O(k)** recursion (+ output). Why: choose k from 9 (section 4).

## 8. Trade-offs & Alternatives
Bitmask over 9 bits is also clear. Sorting not needed (domain sorted).

## 9. Common Mistakes / Edge Cases
Allowing reuse; starting next at `x` not `x+1`; not pruning when digit exceeds remain.

## 10. Interview Follow-ups / Variations
Combination Sum I/II; count only; unlimited range beyond 9.

## 11. Tags
`backtracking`, `combinations`, `leetcode-216`, `difficulty:medium`
