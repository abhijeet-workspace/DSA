# Permutations

## Problem Statement
[LeetCode 46](https://leetcode.com/problems/permutations/) — return all permutations of `nums` (distinct integers).

- **Inputs:** `vector<int> nums` with unique values.
- **Output:** `vector<vector<int>>` — all orderings.
- **Valid answer:** all N! permutations; any order of the list.
- **Edges:** `n=1`; already sorted / reverse sorted.

## Intuition
Fix position `start` by swapping each remaining index `i≥start` into `start`, recurse on `start+1`, then swap back.

## Brute Force → Optimal
- **Brute:** generate all sequences with used[] and skip used values — O(N·N!).
- **Optimal (in-place swap):** same asymptotics, O(1) extra beyond recursion/output (no used array).

## Data Structure / Approach Justification
**Chosen:** in-place swap backtracking on `nums`.

- **vs used[] + path vector:** clearer mentally, more auxiliary memory.
- **vs `std::next_permutation` loop:** fine for generation; less educational for interview DFS.

## Logic Walkthrough
If `start==n`, push copy of `nums`. Else for `i` in `[start,n)`: swap(`start`,`i`), recurse `start+1`, swap again.

## Dry Run
`nums=[1,2,3]`, `start=0`:
- i=0 → `[1,2,3]` → perms starting with 1: `[1,2,3]`, `[1,3,2]`
- i=1 → swap → `[2,1,3]` → `[2,1,3]`, `[2,3,1]`
- i=2 → `[3,2,1]` → `[3,2,1]`, `[3,1,2]`

## Time & Space Complexity
Time **O(N · N!)** (N! perms × O(N) copy). Space **O(N)** recursion (plus output). Why: N choices then N−1 … (section 4).

## Trade-offs & Alternatives
Swap style mutates input (restore by final swaps). Prefer path+used if input must stay pristine without care. With duplicates → Permutations II (sort + skip).

## Common Mistakes / Edge Cases
Forgetting the undo swap; pushing a reference without copying; assuming sorted input.

## Interview Follow-ups / Variations
Duplicates (47). Next permutation. kth permutation. Generate combinations instead.

## Tags
`backtracking`, `permutations`, `swap`, `leetcode-46`, `difficulty:medium`
