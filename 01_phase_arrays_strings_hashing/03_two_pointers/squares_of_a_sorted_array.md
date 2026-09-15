# Squares of a Sorted Array

## 1. Problem Statement
[LeetCode 977](https://leetcode.com/problems/squares-of-a-sorted-array/) — return an array of the squares of each number, sorted in non-decreasing order. Input is already sorted.

- **Input:** sorted `vector<int> nums` (may contain negatives)
- **Output:** sorted squares
- **Edges:** all negative; all non-negative; zeros; single element

## 2. Intuition
Largest squares come from the largest magnitudes — extremes of the sorted array. Compare `|nums[L]|` vs `|nums[R]|` and place the larger square at the end of the result.

## 3. Brute Force → Optimal
- **Brute:** square all then sort — O(N log N).
- **Optimal:** two pointers fill result from right — O(N).

## 4. Data Structure / Approach Justification
Two pointers + result buffer of size N. Order of input makes merge-from-ends correct without a sort.

| Alternative | Why it loses here |
|-------------|-------------------|
| Square + `sort` | Extra log factor |
| Find first non-negative then merge | Same O(N), more bookkeeping |

## 5. Logic Walkthrough
1. `L=0`, `R=n-1`, `write=n-1`.
2. Compare squares at L and R; place the larger at `result[write]`, move that pointer and `--write`.
3. Repeat until L > R.

## 6. Dry Run
`[-4,-1,0,3,10]`: 100 vs 16 → place 100; 16 vs 9 → 16; 9 vs 0 → 9; 1 vs 0 → 1; 0 → `[0,1,9,16,100]`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) for output (O(1) extra beyond that)
- Why: each index consumed once.

## 8. Trade-offs & Alternatives
In-place is awkward because squares expand magnitudes and order changes. Square+sort is fine for small N.

## 9. Common Mistakes / Edge Cases
Filling from the left with wrong comparisons; integer overflow on large |nums[i]| (use `long` for product); empty array.

## 10. Interview Follow-ups / Variations
Sort by absolute value first; merge two sorted halves after split at zero.

## 11. Tags
`two-pointers`, `sorting`, `array`, `leetcode-977`, `easy`
