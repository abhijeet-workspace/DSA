# Number of Closed Islands

## 1. Problem Statement
[LeetCode 1254](https://leetcode.com/problems/number-of-closed-islands/) — count islands of `0` (land) fully surrounded by `1` (water); islands touching the border are not closed.

- **Inputs:** `grid` of `0`/`1`.
- **Output:** number of closed islands.
- **Valid answer:** land components with no border cell.
- **Edges:** all water; land only on border; single interior cell.

## 2. Intuition
First flood-fill (sink) every land cell reachable from the border. Remaining `0` components are closed; count them with DFS/BFS.

## 3. Brute Force → Optimal
- **Brute:** for each island, scan if any cell is on border — O(RC) with care.
- **Optimal:** border DFS then count interior — **O(RC)**.

## 4. Data Structure / Approach Justification
**Chosen:** in-place DFS sink from borders, then count.

- **vs Union-Find:** more code for same asymptotics.
- **vs separate visited:** safer if grid must stay intact.

## 5. Logic Walkthrough
DFS from all border cells through `0`s. Then scan interior; each remaining `0` starts a closed island (++count + flood).

## 6. Dry Run
LC sample: two interior land blobs survive after border elimination → `2`.

## 7. Time & Space Complexity
Time **O(RC)**. Space **O(RC)** recursion. Why: each cell ≤ once (section 4).

## 8. Trade-offs & Alternatives
BFS from border queue. Invert definition: land=`1` in some variants (200 style).

## 9. Common Mistakes / Edge Cases
Counting border-touching islands; confusing `0`/`1` meaning vs Number of Islands.

## 10. Interview Follow-ups / Variations
Number of islands (200); max area; perimeter; distinct shapes.

## 11. Tags
`grid`, `dfs`, `connected-components`, `leetcode-1254`, `difficulty:medium`
