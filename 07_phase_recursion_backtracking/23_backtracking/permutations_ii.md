# Permutations II

## 1. Problem Statement
[LeetCode 47](https://leetcode.com/problems/permutations-ii/) — return all unique permutations of `nums` (may contain duplicates).

- **Inputs:** `vector<int> nums` (duplicates allowed).
- **Output:** `vector<vector<int>>` — unique orderings only.
- **Valid answer:** each distinct sequence once; any order of the list.
- **Edges:** all equal; all distinct; `n=1`.

## 2. Intuition
Sort first so equal values sit together. At each depth, skip a value if the previous identical value was not used — that means this duplicate branch was already explored via the earlier index.

## 3. Brute Force → Optimal
- **Brute:** generate all N! then dedupe with a set — wasteful and still exponential.
- **Optimal:** sorted + skip-on-unused-prev — generate only unique perms.

## 4. Data Structure / Approach Justification
**Chosen:** `used[]` + path vector after sorting.

- **vs swap-in-place:** harder to prune duplicates cleanly.
- **vs set of results:** correct but slower and hides the pruning lesson.

## 5. Logic Walkthrough
Sort `nums`. Recurse building `path`; for each unused `i`, if `nums[i]==nums[i-1]` and `!used[i-1]`, skip. Mark, push, recurse, undo.

## 6. Dry Run
`[1,1,2]` sorted:
- Take first `1` → then second `1` → `2` → `[1,1,2]`
- Take first `1` → then `2` → second `1` → `[1,2,1]`
- Skip second `1` at depth 0 (prev unused) → take `2` → `[2,1,1]`

## 7. Time & Space Complexity
Time **O(N · U)** where U ≤ N! unique perms. Space **O(N)** recursion/used (plus output). Why: each unique leaf copied once (section 4).

## 8. Trade-offs & Alternatives
Swap style works with extra care on duplicate branches. Prefer path+used for interview clarity.

## 9. Common Mistakes / Edge Cases
Skipping when previous *is* used (wrong — that continues a valid branch); forgetting sort; treating like Permutations I.

## 10. Interview Follow-ups / Variations
Combinations with duplicates (40). Next permutation with duplicates. Count unique perms without listing.

## 11. Tags
`backtracking`, `permutations`, `duplicates`, `leetcode-47`, `difficulty:medium`
