# First Missing Positive

## Problem Statement
[LeetCode 41](https://leetcode.com/problems/first-missing-positive/) — find the smallest missing positive integer in unsorted `nums` using O(1) extra space.

- **Inputs:** `vector<int> nums` (may contain negatives, zeros, large values).
- **Output:** smallest positive integer not present.
- **Valid answer:** in `[1, n+1]`.
- **Edges:** all negatives; already has `1..n`; duplicates; zeros.

## Intuition
Only values in `[1, n]` can affect the answer. Cyclic-sort those into index `v - 1`, then scan for the first hole.

## Brute Force → Optimal
- **Brute:** hash set of positives, probe `1,2,...` — O(N) time, O(N) space.
- **Optimal:** in-place cyclic placement — O(N) time, O(1) extra.

## Data Structure / Approach Justification
**Chosen:** swap `v` into `nums[v-1]` only when `1 ≤ v ≤ n` and not already home.

- **vs sort:** O(N log N), unnecessary when range of interest is `1..n`.
- **vs bool array:** uses O(N) space.

## Logic Walkthrough
Place valid positives. Then for `i` in `0..n-1`, if `nums[i] != i+1` return `i+1`; else return `n+1`.

## Dry Run
`nums = [3,4,-1,1]`:
- place → `[1,-1,3,4]`
- scan: index `1` ≠ `2` → return `2`

## Time & Space Complexity
Time **O(N)**. Space **O(1)** auxiliary. Why: bounded swaps over fixed range (section 4).

## Trade-offs & Alternatives
Hash set is clearer but fails the O(1)-space constraint. Sorting is simpler for interviews that ignore complexity.

## Common Mistakes / Edge Cases
Swapping when `v` equals `nums[v-1]` (infinite loop); treating `0` as positive; forgetting answer can be `n+1`.

## Interview Follow-ups / Variations
Missing number with `[0,n]`; find duplicate; stream of positives with limited memory.

## Tags
`cyclic-sort`, `array`, `in-place`, `difficulty:hard`
