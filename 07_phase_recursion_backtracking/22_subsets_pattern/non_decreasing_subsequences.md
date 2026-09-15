# Non-decreasing Subsequences

## 1. Problem Statement
[LeetCode 491](https://leetcode.com/problems/non-decreasing-subsequences/) — find all different non-decreasing subsequences of `nums` with length at least 2.

- **Inputs:** `vector<int> nums` (may contain duplicates).
- **Output:** list of subsequences (unique as sequences).
- **Valid answer:** order of list free; each sequence preserves relative order from `nums`.
- **Edges:** strictly decreasing → empty; all equal; duplicates.

## 2. Intuition
Cascade DFS: append `nums[i]` only if `>=` last; skip same value at the same depth to dedupe (like Subsets II).

## 3. Brute Force → Optimal
- **Brute:** all subsequences then filter/dedupe with a set — heavier.
- **Optimal:** DFS with per-level used set.

## 4. Data Structure / Approach Justification
**Chosen:** for-loop DFS + `unordered_set` used at each call.

- **vs global set of vectors:** more memory and hashing of lists.

## 5. Logic Walkthrough
If path size ≥ 2, record. For `i=start..n-1`: skip if < last or value used this level; push, recurse `i+1`, pop.

## 6. Dry Run
`[4,6,7,7]` → 8 subsequences including `[4,6,7]`, `[4,6,7,7]`, `[7,7]`, etc.

## 7. Time & Space Complexity
Time **O(2^n · n)** worst. Space **O(n)** recursion (+ output). Why: subsequence tree (section 4).

## 8. Trade-offs & Alternatives
Sort+unique does not apply (order must stay). Bitmask enumeration also works for n≤15.

## 9. Common Mistakes / Edge Cases
Treating as subsets (losing order); not deduping duplicates; allowing length 1.

## 10. Interview Follow-ups / Variations
Longest non-decreasing subsequence length (DP); count only.

## 11. Tags
`backtracking`, `subsequences`, `leetcode-491`, `difficulty:medium`
