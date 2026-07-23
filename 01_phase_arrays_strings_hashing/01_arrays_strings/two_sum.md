# Two Sum

## Problem Statement
[LeetCode 1](https://leetcode.com/problems/two-sum/) — return indices of two numbers in `nums` that add up to `target`.

- **Inputs:** `vector<int> nums`, `int target`.
- **Output:** `{i, j}` with `i != j`, `nums[i] + nums[j] == target`.
- **Valid answer:** any valid index pair (problem guarantees exactly one).
- **Edges:** negatives; duplicates; `2 * nums[i] == target` (must use two distinct indices).

## Intuition
While scanning left-to-right, each value `x` needs complement `target - x` already seen. A hash map stores `value -> index`.

## Brute Force → Optimal
- **Brute:** try every pair `(i, j)` — O(N²) time, O(1) space.
- **Optimal:** one pass with `unordered_map` — O(N) average time, O(N) space.

## Data Structure / Approach Justification
**Chosen:** `unordered_map<int,int>` for O(1) average complement lookup while preserving original indices.

- **vs sort + two pointers:** finds values, not indices, unless you track originals — O(N log N).
- **vs nested loops:** no extra memory but fails interview time targets for large N.

## Logic Walkthrough
For each `i`, compute `need = target - nums[i]`. If `need` is in `seen`, return `{seen[need], i}`. Else store `nums[i] -> i`.

## Dry Run
`nums=[2,7,11,15]`, `target=9`:
- `i=0`, `x=2`, `need=7`, map `{}` → store `2→0`
- `i=1`, `x=7`, `need=2`, map has `2@0` → return `{0,1}`

## Time & Space Complexity
Time **O(N)** average (one pass + hash ops). Space **O(N)** for the map. Why: hash enables constant-time complement checks (section 4).

## Trade-offs & Alternatives
Hash uses extra memory for linear time — fine for interviews. Sorted + two pointers preferred when indices are not required.

## Common Mistakes / Edge Cases
Returning the same index twice when `2*nums[i]==target`; assuming unique values; using `map` instead of `unordered_map` without need.

## Interview Follow-ups / Variations
Multiple answers / all pairs? Input sorted → prefer two pointers. Three Sum / Two Sum II.

## Tags
`array`, `hash-map`, `one-pass`, `difficulty:easy`
