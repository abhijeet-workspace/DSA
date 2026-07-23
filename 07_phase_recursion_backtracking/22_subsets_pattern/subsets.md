# Subsets

## Problem Statement
[LeetCode 78](https://leetcode.com/problems/subsets/) — return all possible subsets (the power set) of `nums`. Elements are distinct; subset order does not matter.

- **Inputs:** `vector<int> nums` (distinct).
- **Output:** all `2^N` subsets including `[]` and full set.
- **Valid answer:** any order of subsets / elements within a subset.
- **Edges:** empty `nums` → `[[]]`; single element; larger N (output size dominates).

## Intuition
At each index from `start`, either skip remaining choices or append `nums[i]` and continue with `i+1`. Recording the path at every call captures every subset.

## Brute Force → Optimal
- **Brute:** bitmasks `0..(1<<N)-1` — also optimal asymptotically.
- **Optimal:** DFS backtracking or iterative doubling — both O(N · 2^N) output-bound.

## Data Structure / Approach Justification
**Chosen:** for-loop DFS: push path snapshot first, then extend with later indices.

- **vs include/exclude recursion:** equivalent; two explicit branches per index.
- **vs iterative BFS:** start `[[]]`, for each num duplicate and append — same complexity.
- **vs bitmasks:** very clear when N ≤ 20; no recursion.

## Logic Walkthrough
`result.push(curr)`. For `i` from `start`: push `nums[i]`, recurse `i+1`, pop. Starts at `start=0` with empty `curr`.

## Dry Run
`nums=[1,2,3]`:
- `[]`, `[1]`, `[1,2]`, `[1,2,3]`, `[1,3]`, `[2]`, `[2,3]`, `[3]`
- **8** subsets

## Time & Space Complexity
Time **O(N · 2^N)** (copy each subset). Space **O(N)** recursion (+ O(N · 2^N) output). Why: power-set size 2^N (section 4).

## Trade-offs & Alternatives
Backtracking matches combination templates. Iterative/bitmask preferred if recursion depth is a concern. Cascading copy in iterative form is cache-friendly for small N.

## Common Mistakes / Edge Cases
Forgetting empty subset; using `i` instead of `i+1` (duplicates / infinite); sorting when not required; mutating input.

## Interview Follow-ups / Variations
Subsets II (90, duplicates); combinations of size k; permute vs subset distinction.

## Tags
`backtracking`, `dfs`, `power-set`, `leetcode-78`, `difficulty:medium`
