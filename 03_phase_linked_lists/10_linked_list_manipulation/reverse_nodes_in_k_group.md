# Reverse Nodes in k-Group

## 1. Problem Statement
[LeetCode 25](https://leetcode.com/problems/reverse-nodes-in-k-group/) — reverse nodes of a list `k` at a time; if fewer than `k` remain, leave them unchanged.

- **Inputs:** `head`, positive integer `k`.
- **Output:** new head after group reversals.
- **Valid answer:** every complete block of `k` reversed; leftover suffix intact.
- **Edges:** `k=1` (no-op); `k=N` (full reverse); leftover `<k`; empty.

## 2. Intuition
Count length, then iteratively reverse each full window of `k`, stitching group boundaries with a dummy/`prevGroup` pointer.

## 3. Brute Force → Optimal
- **Brute:** store nodes in a vector and rebuild — O(N) space.
- **Optimal:** iterative in-place group reverse — O(1) auxiliary (this file).

## 4. Data Structure / Approach Justification
**Chosen:** length count + iterative k-reverse with dummy.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Recursion on groups | O(N/k) stack |
| Check-ahead without count | Also valid; count is simple and clear |

## 5. Logic Walkthrough
1. While `count >= k`, reverse next `k` nodes from `currGroup`.
2. Reconnect `prevGroup->next` to new head; old head (`groupTail`) to remainder.
3. Advance `prevGroup`/`currGroup`, subtract `k`.

## 6. Dry Run
`1→2→3→4→5`, `k=2`: reverse `(1,2)` → `2→1→3→4→5`; reverse `(3,4)` → `2→1→4→3→5`; leftover `5`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Look-ahead “have k nodes?” avoids a full count pass; same asymptotics. Recursive solution is shorter but uses stack.

## 9. Common Mistakes / Edge Cases
Reversing a short leftover group; losing the link to the next group; `k=1` infinite or no-op bugs.

## 10. Interview Follow-ups / Variations
Swap pairs (`k=2`); reverse only alternate groups; reverse between left/right.

## 11. Tags
`linked-list`, `reverse`, `k-group`, `dummy-node`, `leetcode-25`, `difficulty:hard`
