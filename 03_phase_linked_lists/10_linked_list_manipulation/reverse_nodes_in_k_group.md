# Reverse Nodes in k-Group

## Problem Statement
[LeetCode 25](https://leetcode.com/problems/reverse-nodes-in-k-group/) — reverse nodes of a list `k` at a time; if fewer than `k` remain, leave them unchanged.

- **Inputs:** `head`, positive integer `k`.
- **Output:** new head after group reversals.
- **Valid answer:** every complete block of `k` reversed; leftover suffix intact.
- **Edges:** `k=1` (no-op); `k=N` (full reverse); leftover `<k`; empty.

## Intuition
Count length, then iteratively reverse each full window of `k`, stitching group boundaries with a dummy/`prevGroup` pointer.

## Brute Force → Optimal
- **Brute:** store nodes in a vector and rebuild — O(N) space.
- **Optimal:** iterative in-place group reverse — O(1) auxiliary (this file).

## Data Structure / Approach Justification
**Chosen:** length count + iterative k-reverse with dummy.

- **vs recursion on groups:** O(N/k) stack.
- **vs check-ahead without count:** also valid; count is simple and clear.

## Logic Walkthrough
While `count >= k`, reverse next `k` nodes from `currGroup`, reconnect `prevGroup->next` to new head, old head (`groupTail`) to remainder, advance `prevGroup`/`currGroup`, subtract `k`.

## Dry Run
`1→2→3→4→5`, `k=2`: reverse `(1,2)` → `2→1→3→4→5`; reverse `(3,4)` → `2→1→4→3→5`; leftover `5`.

## Time & Space Complexity
Time **O(N)** (count + each node reversed at most once). Space **O(1)**. Why: constant pointers per group (section 4).

## Trade-offs & Alternatives
Look-ahead “have k nodes?” avoids a full count pass; same asymptotics. Recursive solution is shorter but uses stack.

## Common Mistakes / Edge Cases
Reversing a short leftover group; losing the link to the next group; `k=1` infinite or no-op bugs.

## Interview Follow-ups / Variations
Swap pairs (`k=2`); reverse only alternate groups; reverse between left/right.

## Tags
`linked-list`, `reverse`, `k-group`, `dummy-node`, `difficulty:hard`
