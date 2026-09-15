# Subsets II

## 1. Problem Statement
[LeetCode 90](https://leetcode.com/problems/subsets-ii/) — return all unique subsets of `nums`, which may contain duplicates. The solution set must not contain duplicate subsets.

- **Inputs:** `vector<int> nums` (may have duplicates).
- **Output:** unique power set (including `[]`).
- **Valid answer:** each distinct multiset once; any order.
- **Edges:** all equal; no duplicates (reduces to Subsets); empty; two duplicates only.

## 2. Intuition
Sort so equal values are adjacent. In the for-loop at a given depth, skip `nums[i]` when it equals `nums[i-1]` and `i > start` — that branch was already explored by taking the earlier copy.

## 3. Brute Force → Optimal
- **Brute:** generate all subsets then insert into a set of sorted tuples — correct but slower/messier.
- **Optimal:** sort + same-depth duplicate skip during DFS.

## 4. Data Structure / Approach Justification
**Chosen:** sorted backtracking identical to Subsets, plus `i > start && nums[i]==nums[i-1]` continue.

- **vs Subsets (78):** same template; skip handles uniqueness.
- **vs hash-set of subsets:** hides the algorithm; extra log / hash cost.
- **vs count-map construction:** build by frequency ranges — also valid, less common in interviews.

## 5. Logic Walkthrough
Sort. Push current path. For `i` from `start`: skip duplicates at same depth; push `nums[i]`, recurse `i+1`, pop.

## 6. Dry Run
`nums=[1,2,2]` → sorted same:
- `[]`, `[1]`, `[1,2]`, `[1,2,2]`, `[2]`, `[2,2]`
- second root-level `2` skipped after first `2` branch
- **6** unique subsets

## 7. Time & Space Complexity
Time **O(N · 2^N)** worst (distinct-heavy). Space **O(N)** recursion (+ output). Why: still exponential unique subsets; sort is O(N log N) upfront (section 4).

## 8. Trade-offs & Alternatives
Skip-duplicates matches Combination Sum II. Frequency-map “add 0..count copies” is clean when teaching multisets. Set-dedup is a last resort.

## 9. Common Mistakes / Edge Cases
Using `i > 0` instead of `i > start`; forgetting sort; treating Subsets II like permutations; missing empty subset.

## 10. Interview Follow-ups / Variations
Combination Sum II (40); permutations with duplicates (47); unique combinations of size k.

## 11. Tags
`backtracking`, `dfs`, `power-set`, `duplicates`, `leetcode-90`, `difficulty:medium`
