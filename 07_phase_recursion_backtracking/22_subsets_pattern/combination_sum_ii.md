# Combination Sum II

## Problem Statement
[LeetCode 40](https://leetcode.com/problems/combination-sum-ii/) — find all unique combinations that sum to `target`. Each candidate may be used at most once; input may contain duplicates.

- **Inputs:** `vector<int> candidates`, `int target`.
- **Output:** unique combinations (no duplicate multisets).
- **Valid answer:** each combo uses distinct indices; same values from different indices allowed only if both are chosen.
- **Edges:** duplicate values; target 0; all values > target; multiple identical paths after sort.

## Intuition
Sort, then DFS from `start`. Skip a value when it equals the previous at the same recursion depth so identical branches are not explored twice. Advance `i + 1` so each index is used once.

## Brute Force → Optimal
- **Brute:** all subsets, filter by sum, dedupe with a set — O(2^N) plus heavy uniqueness cost.
- **Optimal:** sort + backtrack with same-depth duplicate skip and early break when value > remain.

## Data Structure / Approach Justification
**Chosen:** sorted array + for-loop DFS with `i > start && nums[i]==nums[i-1]` skip.

- **vs Combination Sum (39):** no reuse (`i+1`); must handle duplicates.
- **vs set of vectors:** correctness without sorting/skip, but worse constants and messier.
- **vs bitmasks:** same exponential; harder duplicate control.

## Logic Walkthrough
Sort. At depth, for `i` from `start`: break if `candidates[i] > target`; skip duplicates at same depth; push, recurse `target - candidates[i]` with `i+1`, pop.

## Dry Run
`candidates=[10,1,2,7,6,1,5]`, `target=8` → sorted `[1,1,2,5,6,7,10]`:
- `[1,1,6]`, `[1,2,5]`, `[1,7]`, `[2,6]`
- second leading `1` at root level skipped after first branch
- **4** unique combos

## Time & Space Complexity
Time **O(2^N)** worst (subset tree; pruning helps). Space **O(N)** recursion (+ output). Why: each index include/exclude once after sort (section 4).

## Trade-offs & Alternatives
Skip-duplicates is interview-standard. Hash-set of sorted combos is simpler to write but slower and less “algorithmic.” Count-only DP if listing is not required.

## Common Mistakes / Edge Cases
Skipping with `i > 0` instead of `i > start` (kills valid same-value different indices); reusing index; forgetting sort; not breaking on sorted overflow.

## Interview Follow-ups / Variations
Combination Sum (39, unlimited reuse); Subsets II (90); k-sum variants.

## Tags
`backtracking`, `dfs`, `combination`, `duplicates`, `leetcode-40`, `difficulty:medium`
