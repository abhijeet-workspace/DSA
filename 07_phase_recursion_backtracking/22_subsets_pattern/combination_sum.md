# Combination Sum

## Problem Statement
[LeetCode 39](https://leetcode.com/problems/combination-sum/) — return all unique combinations from `candidates` that sum to `target`. Candidates are distinct; each may be reused unlimited times.

- **Inputs:** `vector<int> candidates`, `int target`.
- **Output:** list of combinations (order of combos / within a combo may vary by convention).
- **Valid answer:** every combo sums to `target`; same multiset listed once.
- **Edges:** target smaller than min; exact single candidate; many small values; empty result.

## Intuition
At each index, either take `candidates[i]` again (reuse) or advance to `i+1`. Index discipline avoids listing permutations of the same multiset.

## Brute Force → Optimal
- **Brute:** generate all multisets / permutations then filter by sum — huge duplicates.
- **Optimal:** DFS backtracking with remaining-target prune — standard LC solution.

## Data Structure / Approach Justification
**Chosen:** recursive backtracking with current path + remaining target; reuse same index on take.

- **vs always advancing index:** forbids reuse (Combination Sum II / III).
- **vs DP coin-change collecting lists:** heavier memory and harder uniqueness control.
- **vs sorting first:** optional early prune when `candidates[i] > remain`.

## Logic Walkthrough
Base: `remain == 0` → push path; `remain < 0` or `index` out of range → return. Else push `candidates[index]`, recurse with same `index`, pop, then recurse with `index + 1`.

## Dry Run
`candidates=[2,3,6,7]`, `target=7`:
- path `[2,2,3]` via reuse of 2 then take 3
- path `[7]` via skip to 7
- result size **2**

## Time & Space Complexity
Time roughly **O(N^{T/M})** (branching by candidates, depth ~ target / min). Space **O(T/M)** recursion depth (+ output). Why: search tree of reuse/skip decisions (section 4).

## Trade-offs & Alternatives
Include/exclude style is clean. Sort + for-loop with prune can cut branches earlier. DP if you need counts only or bottom-up rebuild.

## Common Mistakes / Edge Cases
Advancing index always (no reuse); allowing permutations as distinct; not pruning negative remain; mutating `candidates` unexpectedly.

## Interview Follow-ups / Variations
Combination Sum II (40, each once + duplicates); Combination Sum III (k numbers); count combinations only.

## Tags
`backtracking`, `dfs`, `combination`, `leetcode-39`, `difficulty:medium`
